# TurtleRec API

Core endpoints planned:

## Auth
POST /auth/login
POST /auth/register
POST /auth/refresh

## Players
GET /players/me
GET /players/:id
PATCH /players/:id/profile

## Rooms
GET /rooms
GET /rooms/:id
POST /rooms/join
POST /rooms/create

## Matchmaking
POST /matchmaking/join
POST /matchmaking/leave

## Images
POST /images/upload
GET /images/:id

## Notifications
GET /notifications
POST /notifications/send

## Economy
GET /economy/wallet
POST /economy/purchase

## Moderation
POST /reports
GET /bans
POST /appeals
