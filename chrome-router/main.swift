// Default-browser shim: opens links in a visible, non-fullscreen Chrome window
// on the main display, so a fullscreen video on another display stays untouched.
import AppKit

let chromeID = "com.google.Chrome"

struct ChromeWindow { let id: String; let rect: CGRect }

func runScript(_ source: String) -> NSAppleEventDescriptor? {
    var error: NSDictionary?
    let result = NSAppleScript(source: source)?.executeAndReturnError(&error)
    if let error { NSLog("chrome-router: \(error)") }
    return error == nil ? result : nil
}

func literal(_ s: String) -> String {
    "\"" + s.replacingOccurrences(of: "\\", with: "\\\\")
            .replacingOccurrences(of: "\"", with: "\\\"") + "\""
}

// Chrome's own z-ordered window list, front window first.
func chromeWindows() -> [ChromeWindow]? {
    let script = """
    tell application id "\(chromeID)"
        set out to ""
        repeat with w in windows
            set b to bounds of w
            set out to out & (id of w) & " " & (item 1 of b) & " " & (item 2 of b) & " " & (item 3 of b) & " " & (item 4 of b) & linefeed
        end repeat
        return out
    end tell
    """
    guard let text = runScript(script)?.stringValue else { return nil }
    return text.split(separator: "\n").compactMap { line in
        let p = line.split(separator: " ")
        guard p.count == 5, let l = Double(p[1]), let t = Double(p[2]),
              let r = Double(p[3]), let b = Double(p[4]) else { return nil }
        return ChromeWindow(id: String(p[0]), rect: CGRect(x: l, y: t, width: r - l, height: b - t))
    }
}

// Rects of Chrome windows on the Spaces shown right now. Needs no Screen Recording permission.
func visibleRects() -> [CGRect] {
    let list = CGWindowListCopyWindowInfo([.optionOnScreenOnly, .excludeDesktopElements], kCGNullWindowID)
        as? [[String: Any]] ?? []
    return list.compactMap { info in
        guard info[kCGWindowOwnerName as String] as? String == "Google Chrome",
              info[kCGWindowLayer as String] as? Int == 0,
              let d = info[kCGWindowBounds as String] as? NSDictionary else { return nil }
        return CGRect(dictionaryRepresentation: d)
    }
}

// Chrome's AppleScript cannot make a window key, so this goes through Accessibility.
// Without that permission Chrome still comes forward, on its last used window.
func raise(_ rect: CGRect) {
    guard let chrome = NSRunningApplication.runningApplications(withBundleIdentifier: chromeID).first else { return }
    defer { chrome.activate() }
    let ax = AXUIElementCreateApplication(chrome.processIdentifier)
    var value: CFTypeRef?
    guard AXUIElementCopyAttributeValue(ax, kAXWindowsAttribute as CFString, &value) == .success,
          let list = value as? [AXUIElement] else { return }
    for window in list where axRect(window) == rect {
        AXUIElementPerformAction(window, kAXRaiseAction as CFString)
        AXUIElementSetAttributeValue(window, kAXMainAttribute as CFString, kCFBooleanTrue)
        return
    }
}

func axRect(_ window: AXUIElement) -> CGRect? {
    var position: CFTypeRef?, size: CFTypeRef?
    guard AXUIElementCopyAttributeValue(window, kAXPositionAttribute as CFString, &position) == .success,
          AXUIElementCopyAttributeValue(window, kAXSizeAttribute as CFString, &size) == .success else { return nil }
    var origin = CGPoint.zero, extent = CGSize.zero
    AXValueGetValue(position as! AXValue, .cgPoint, &origin)
    AXValueGetValue(size as! AXValue, .cgSize, &extent)
    return CGRect(origin: origin, size: extent)
}

func fallback(_ url: URL) {
    guard let chrome = NSWorkspace.shared.urlForApplication(withBundleIdentifier: chromeID) else { return }
    let done = DispatchSemaphore(value: 0)
    NSWorkspace.shared.open([url], withApplicationAt: chrome, configuration: .init()) { _, _ in done.signal() }
    _ = done.wait(timeout: .now() + 5)
}

func open(_ url: URL) {
    let isRunning = !NSRunningApplication.runningApplications(withBundleIdentifier: chromeID).isEmpty
    guard isRunning, let windows = chromeWindows() else { return fallback(url) }

    let main = CGDisplayBounds(CGMainDisplayID())
    let visible = visibleRects()
    let target = windows.first { w in
        main.contains(CGPoint(x: w.rect.midX, y: w.rect.midY))
            && w.rect != main              // a fullscreen window fills the whole display
            && visible.contains(w.rect)
    }

    let link = literal(url.absoluteString)
    let script: String
    if let target {
        script = """
        tell application id "\(chromeID)"
            tell window id "\(target.id)"
                make new tab with properties {URL:\(link)}
            end tell
        end tell
        """
    } else {
        // Cocoa puts the origin at the bottom left, bounds want it at the top left.
        let screen = NSScreen.screens[0]
        let v = screen.visibleFrame
        let top = screen.frame.maxY - v.maxY
        script = """
        tell application id "\(chromeID)"
            set w to make new window
            set bounds of w to {\(Int(v.minX)), \(Int(top)), \(Int(v.maxX)), \(Int(top + v.height))}
            set URL of active tab of w to \(link)
            activate
        end tell
        """
    }
    if runScript(script) == nil { return fallback(url) }
    if let target { raise(target.rect) }
}

final class Delegate: NSObject, NSApplicationDelegate {
    func applicationDidFinishLaunching(_ note: Notification) {
        _ = AXIsProcessTrustedWithOptions(["AXTrustedCheckOptionPrompt": true] as CFDictionary)
        // Launched without a URL, so there is nothing to do.
        DispatchQueue.main.asyncAfter(deadline: .now() + 3) { NSApp.terminate(nil) }
    }
    func application(_ app: NSApplication, open urls: [URL]) {
        urls.forEach(open)
        NSApp.terminate(nil)
    }
}

let app = NSApplication.shared
let delegate = Delegate()
app.delegate = delegate
app.setActivationPolicy(.prohibited)
app.run()
