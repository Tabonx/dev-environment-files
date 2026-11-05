# Chrome Router

Chrome sends a link to its last active window. If that window is a fullscreen video on the second display, the video drops out of fullscreen and the link opens there.

Chrome Router is a small macOS app with no UI, set as the default browser. For each link it picks the window itself:

1. A visible, non-fullscreen Chrome window on the main display gets a new tab and comes to the front.
2. If there is no such window, it opens a new one on the main display.
3. If Chrome isn't running or the script fails, it hands the link to Chrome as usual.

## Install

```sh
./build.sh
swift set-default.swift
```

`build.sh` installs the app to `~/Applications/Chrome Router.app`. `set-default.swift` makes it the handler for http and https.

Then open any link. macOS asks to let Chrome Router control Google Chrome, so allow it. Turn on Chrome Router in System Settings > Privacy & Security > Accessibility. Without that the tab lands in the right window, but Chrome raises the fullscreen one.

The app has an ad-hoc signature, so every rebuild invalidates the Accessibility permission. Turn it off and on again after `build.sh`.

## Limits

- The app only sees windows on the current Space. A Chrome window on another Space doesn't count, so you get a new window here.
- If you open a link from Chrome itself while its fullscreen window is key and the main display has no Chrome window, the new window lands on the fullscreen Space.

## Uninstall

Pick Google Chrome in System Settings > Desktop & Dock > Default web browser, then delete the app.
