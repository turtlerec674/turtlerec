cmake_minimum_required(VERSION 3.16)
project(RRServerMonoCpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SQLite3 REQUIRED)

add_executable(rrserver
    src/main.cpp
    src/accounts/account.cpp
    src/rooms/room.cpp
    src/matchmaking/matchmaking.cpp
    src/inventory/inventory.cpp
    src/moderation/moderation.cpp
    src/anticheat/anticheat.cpp
    src/server/server.cpp
    src/friends/friends.cpp
    src/profiles/profiles.cpp
    src/currency/currency.cpp
    src/sessions/sessions.cpp
    src/presence/presence.cpp
    src/parties/parties.cpp
    src/notifications/notifications.cpp
    src/avatar/avatar.cpp
    src/dorms/dorms.cpp
    src/economy/economy.cpp
    src/voice/voice.cpp
    src/messages/messages.cpp
    src/invites/invites.cpp
    src/leaderboards/leaderboards.cpp
    src/achievements/achievements.cpp
    src/clubs/clubs.cpp
    src/blocklist/blocklist.cpp
    src/store/store.cpp
    src/purchases/purchases.cpp
    src/reports/reports.cpp
    src/bans/bans.cpp
    src/logs/logs.cpp
    src/photos/photos.cpp
    src/screenshots/screenshots.cpp
    src/consumables/consumables.cpp
    src/trading/trading.cpp
    src/rrplus/rrplus.cpp
    src/gifts/gifts.cpp
    src/http/httpserver.cpp
    src/sqlite/sqlite.cpp
    src/auth/auth.cpp
    src/assets/assets.cpp
    src/instances/instances.cpp
    src/cloudsave/cloudsave.cpp
    src/equipment/equipment.cpp
    src/quests/quests.cpp
    src/admin/admin.cpp
    src/staff/staff.cpp
    src/live/live.cpp
    src/recnet/recnet.cpp
    src/events/events.cpp
    src/workshop/workshop.cpp
    src/analytics/analytics.cpp
    src/security/security.cpp
    src/cosmetics/cosmetics.cpp
    src/announcements/announcements.cpp
    src/finalsystems/finalsystems.cpp
    src/v1systems/v1systems.cpp
    src/gameplaypack/gameplaypack.cpp
    src/launchpack/launchpack.cpp
    src/backend2/backend2.cpp
    src/backend3/backend3.cpp
    src/backend4/backend4.cpp
    src/realapi/realapi.cpp
    src/phase6/phase6.cpp
    src/phase7/phase7.cpp
)

target_link_libraries(rrserver SQLite3::SQLite3)
