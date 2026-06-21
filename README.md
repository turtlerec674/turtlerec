# TurtleRec / RRServerMonoCpp

TurtleRec backend and connector project.

## Current Status

- RRServer backend runs on port 3000
- SQLite database loads
- Auth, rooms, RecNet, photos, assets, admin and compatibility routes added
- TurtleRecCustomConnector.dll compiled from Android/Termux
- Launcher, branding, config, dashboard and anti-cheat docs added

## Run Backend

    cd ~/RRServerMonoCpp/build
    ./rrserver

Open in your browser:

    http://127.0.0.1:3000/api/status

## Connector

Custom DLL location:

    plugins/TurtleRecConnector/bin/TurtleRecCustomConnector.dll

Important:

Assembly-CSharp.dll must call:

    TurtleRecCustomConnector.Init();

Whenever a URL is generated, redirect it using:

    url = TurtleRecCustomConnector.RedirectUrl(url);

## Planned Features

- Authentication
- RecNet compatibility
- Photon compatibility
- Rooms
- Parties
- Friends
- Photos
- Notifications
- Clubs
- Economy
- Anti-Cheat
- Launcher
- Admin Dashboard
