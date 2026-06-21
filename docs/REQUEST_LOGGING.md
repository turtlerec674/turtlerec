# Request Logging Plan

When the client is patched, every request should be logged.

Target log file:

    logs/requests.log

Log format:

    METHOD PATH TIMESTAMP IP

Purpose:

- Find missing endpoints
- Debug login
- Debug RecNet
- Debug photo uploads
- Debug matchmaking
- Debug Photon joins
