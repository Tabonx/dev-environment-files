import AppKit
let app = URL(fileURLWithPath: NSHomeDirectory() + "/Applications/Chrome Router.app")
let g = DispatchGroup()
for s in ["http", "https"] {
  g.enter()
  NSWorkspace.shared.setDefaultApplication(at: app, toOpenURLsWithScheme: s) { e in print(s, e?.localizedDescription ?? "ok"); g.leave() }
}
g.notify(queue: .main) { exit(0) }
RunLoop.main.run(until: Date().addingTimeInterval(45))
print("timeout")
