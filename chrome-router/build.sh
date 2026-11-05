#!/bin/zsh
set -e
cd "${0:A:h}"
APP="$HOME/Applications/Chrome Router.app"
mkdir -p "$APP/Contents/MacOS"
cp Info.plist "$APP/Contents/Info.plist"
swiftc -O -framework AppKit main.swift -o "$APP/Contents/MacOS/chrome-router"
codesign --force --sign - "$APP"
/System/Library/Frameworks/CoreServices.framework/Frameworks/LaunchServices.framework/Support/lsregister -f "$APP"
