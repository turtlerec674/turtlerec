#include "httpserver.h"
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>

#include "../accounts/account.h"
#include "../rooms/room.h"
#include "../profiles/profiles.h"
#include "../currency/currency.h"
#include "../sessions/sessions.h"
#include "../presence/presence.h"
#include "../friends/friends.h"
#include "../parties/parties.h"
#include "../notifications/notifications.h"
#include "../avatar/avatar.h"
#include "../dorms/dorms.h"
#include "../voice/voice.h"
#include "../messages/messages.h"
#include "../invites/invites.h"
#include "../leaderboards/leaderboards.h"
#include "../achievements/achievements.h"
#include "../clubs/clubs.h"
#include "../store/store.h"
#include "../reports/reports.h"
#include "../bans/bans.h"
#include "../photos/photos.h"
#include "../screenshots/screenshots.h"
#include "../consumables/consumables.h"
#include "../trading/trading.h"
#include "../rrplus/rrplus.h"
#include "../gifts/gifts.h"
#include "../sqlite/sqlite.h"
#include "../auth/auth.h"
#include "../assets/assets.h"
#include "../instances/instances.h"
#include "../cloudsave/cloudsave.h"
#include "../equipment/equipment.h"
#include "../quests/quests.h"
#include "../admin/admin.h"
#include "../staff/staff.h"
#include "../live/live.h"
#include "../recnet/recnet.h"
#include "../events/events.h"
#include "../workshop/workshop.h"
#include "../analytics/analytics.h"
#include "../security/security.h"
#include "../cosmetics/cosmetics.h"
#include "../announcements/announcements.h"
#include "../finalsystems/finalsystems.h"
#include "../v1systems/v1systems.h"
#include "../gameplaypack/gameplaypack.h"
#include "../launchpack/launchpack.h"
#include "../backend2/backend2.h"
#include "../backend3/backend3.h"
#include "../backend4/backend4.h"

static std::string ok(const std::string& body) {
    return "HTTP/1.1 200 OK\r\n"
           "Content-Type: application/json\r\n"
           "Access-Control-Allow-Origin: *\r\n"
           "Access-Control-Allow-Methods: GET, POST, OPTIONS\r\n"
           "Access-Control-Allow-Headers: Content-Type, Authorization\r\n"
           "Connection: close\r\n\r\n" + body;
}

static std::string notFound() {
    return "HTTP/1.1 404 Not Found\r\n"
           "Content-Type: application/json\r\n"
           "Access-Control-Allow-Origin: *\r\n"
           "Connection: close\r\n\r\n{\"error\":\"not_found\"}";
}

static bool has(const std::string& req, const std::string& value) {
    return req.find(value) != std::string::npos;
}

static std::string statusJson() {
    return "{"
        "\"accounts\":" + std::to_string(AccountManager::count()) + ","
        "\"profiles\":" + std::to_string(ProfileManager::count()) + ","
        "\"wallets\":" + std::to_string(CurrencyManager::count()) + ","
        "\"sessions\":" + std::to_string(SessionManager::count()) + ","
        "\"presence\":" + std::to_string(PresenceManager::count()) + ","
        "\"rooms\":" + std::to_string(RoomManager::count()) + ","
        "\"friends\":" + std::to_string(FriendManager::count()) + ","
        "\"parties\":" + std::to_string(PartyManager::count()) + ","
        "\"notifications\":" + std::to_string(NotificationManager::count()) + ","
        "\"avatars\":" + std::to_string(AvatarManager::count()) + ","
        "\"dorms\":" + std::to_string(DormManager::count()) + ","
        "\"voice\":" + std::to_string(VoiceManager::count()) + ","
        "\"messages\":" + std::to_string(MessageManager::count()) + ","
        "\"invites\":" + std::to_string(InviteManager::count()) + ","
        "\"leaderboards\":" + std::to_string(LeaderboardManager::count()) + ","
        "\"achievements\":" + std::to_string(AchievementManager::count()) + ","
        "\"clubs\":" + std::to_string(ClubManager::count()) + ","
        "\"store\":" + std::to_string(StoreManager::count()) + ","
        "\"reports\":" + std::to_string(ReportManager::count()) + ","
        "\"bans\":" + std::to_string(BanManager::count()) + ","
        "\"photos\":" + std::to_string(PhotoManager::count()) + ","
        "\"screenshots\":" + std::to_string(ScreenshotManager::count()) + ","
        "\"consumables\":" + std::to_string(ConsumableManager::count()) + ","
        "\"trades\":" + std::to_string(TradeManager::count()) + ","
        "\"rrplus\":" + std::to_string(RRPlusManager::count()) + ","
        "\"gifts\":" + std::to_string(GiftManager::count()) +
        "}";
}

static std::string route(const std::string& req) {
    if (has(req, "OPTIONS ")) return ok("{\"ok\":true}");

    if (has(req, "GET / ")) {
        return ok("{\"name\":\"RRServer Mono/C++\",\"status\":\"online\",\"version\":\"0.3.0\"}");
    }

    if (has(req, "GET /health")) {
        return ok("{\"status\":\"healthy\"}");
    }

    if (has(req, "GET /api/status")) return ok(statusJson());

    if (has(req, "GET /api/accounts")) return ok("{\"accounts\":" + std::to_string(AccountManager::count()) + "}");
    if (has(req, "GET /api/profiles")) return ok("{\"profiles\":" + std::to_string(ProfileManager::count()) + "}");
    if (has(req, "GET /api/wallets")) return ok("{\"wallets\":" + std::to_string(CurrencyManager::count()) + "}");
    if (has(req, "GET /api/sessions")) return ok("{\"sessions\":" + std::to_string(SessionManager::count()) + "}");
    if (has(req, "GET /api/presence")) return ok("{\"presence\":" + std::to_string(PresenceManager::count()) + "}");
    if (has(req, "GET /api/rooms")) return ok("{\"rooms\":" + std::to_string(RoomManager::count()) + "}");
    if (has(req, "GET /api/friends")) return ok("{\"friends\":" + std::to_string(FriendManager::count()) + "}");
    if (has(req, "GET /api/parties")) return ok("{\"parties\":" + std::to_string(PartyManager::count()) + "}");
    if (has(req, "GET /api/notifications")) return ok("{\"notifications\":" + std::to_string(NotificationManager::count()) + "}");
    if (has(req, "GET /api/avatars")) return ok("{\"avatars\":" + std::to_string(AvatarManager::count()) + "}");
    if (has(req, "GET /api/dorms")) return ok("{\"dorms\":" + std::to_string(DormManager::count()) + "}");
    if (has(req, "GET /api/voice")) return ok("{\"voice_channels\":" + std::to_string(VoiceManager::count()) + "}");
    if (has(req, "GET /api/messages")) return ok("{\"messages\":" + std::to_string(MessageManager::count()) + "}");
    if (has(req, "GET /api/invites")) return ok("{\"invites\":" + std::to_string(InviteManager::count()) + "}");
    if (has(req, "GET /api/leaderboards")) return ok("{\"leaderboards\":" + std::to_string(LeaderboardManager::count()) + "}");
    if (has(req, "GET /api/achievements")) return ok("{\"achievements\":" + std::to_string(AchievementManager::count()) + "}");
    if (has(req, "GET /api/clubs")) return ok("{\"clubs\":" + std::to_string(ClubManager::count()) + "}");
    if (has(req, "GET /api/store")) return ok("{\"store_items\":" + std::to_string(StoreManager::count()) + "}");
    if (has(req, "GET /api/reports")) return ok("{\"reports\":" + std::to_string(ReportManager::count()) + "}");
    if (has(req, "GET /api/bans")) return ok("{\"bans\":" + std::to_string(BanManager::count()) + "}");
    if (has(req, "GET /api/photos")) return ok("{\"photos\":" + std::to_string(PhotoManager::count()) + "}");
    if (has(req, "GET /api/screenshots")) return ok("{\"screenshots\":" + std::to_string(ScreenshotManager::count()) + "}");
    if (has(req, "GET /api/consumables")) return ok("{\"consumables\":" + std::to_string(ConsumableManager::count()) + "}");
    if (has(req, "GET /api/trades")) return ok("{\"trades\":" + std::to_string(TradeManager::count()) + "}");
    if (has(req, "GET /api/rrplus")) return ok("{\"rrplus_subs\":" + std::to_string(RRPlusManager::count()) + "}");
    if (has(req, "GET /api/gifts")) return ok("{\"gifts\":" + std::to_string(GiftManager::count()) + "}");

    if (has(req, "POST /api/accounts/create")) {
        AccountManager::createAccount("http_user", "http@example.com");
        return ok("{\"created\":true,\"accounts\":" + std::to_string(AccountManager::count()) + "}");
    }

    if (has(req, "POST /api/rooms/create")) {
        RoomManager::createRoom("HTTP Room", 20);
        return ok("{\"created\":true,\"rooms\":" + std::to_string(RoomManager::count()) + "}");
    }

    if (has(req, "POST /api/friends/request")) {
        FriendManager::sendRequest(1, 2);
        return ok("{\"created\":true,\"friends\":" + std::to_string(FriendManager::count()) + "}");
    }

    if (has(req, "POST /api/messages/send")) {
        MessageManager::sendMessage(1, 2, "HTTP message");
        return ok("{\"created\":true,\"messages\":" + std::to_string(MessageManager::count()) + "}");
    }

    if (has(req, "POST /api/reports/create")) {
        ReportManager::createReport(1, 99, "HTTP report");
        return ok("{\"created\":true,\"reports\":" + std::to_string(ReportManager::count()) + "}");
    }

    if (has(req, "POST /api/gifts/send")) {
        GiftManager::sendGift(1, 2, 101);
        return ok("{\"created\":true,\"gifts\":" + std::to_string(GiftManager::count()) + "}");
    }

    if (has(req, "GET /api/sqlite")) return ok("{\"accounts\":" + std::to_string(SQLiteDB::count("accounts")) + ",\"profiles\":" + std::to_string(SQLiteDB::count("profiles")) + ",\"wallets\":" + std::to_string(SQLiteDB::count("wallets")) + ",\"rooms\":" + std::to_string(SQLiteDB::count("rooms")) + ",\"friends\":" + std::to_string(SQLiteDB::count("friends")) + ",\"messages\":" + std::to_string(SQLiteDB::count("messages")) + ",\"inventory\":" + std::to_string(SQLiteDB::count("inventory")) + ",\"reports\":" + std::to_string(SQLiteDB::count("reports")) + ",\"bans\":" + std::to_string(SQLiteDB::count("bans")) + ",\"clubs\":" + std::to_string(SQLiteDB::count("clubs")) + ",\"store\":" + std::to_string(SQLiteDB::count("store")) + ",\"photos\":" + std::to_string(SQLiteDB::count("photos")) + ",\"gifts\":" + std::to_string(SQLiteDB::count("gifts")) + ",\"sessions\":" + std::to_string(SQLiteDB::count("sessions")) + ",\"logs\":" + std::to_string(SQLiteDB::count("logs")) + "}");

    if (has(req, "POST /api/auth/register")) return ok(AuthManager::registerUser("http_user"));
    if (has(req, "POST /api/auth/login")) return ok("{\"token\":\"" + AuthManager::loginUser(1) + "\"}");
    if (has(req, "GET /api/auth/tokens")) return ok("{\"tokens\":" + std::to_string(AuthManager::count()) + "}");
    if (has(req, "POST /api/assets/photo")) return ok(AssetManager::uploadPhoto(1));
    if (has(req, "POST /api/assets/avatar")) return ok(AssetManager::uploadAvatar(1));
    if (has(req, "POST /api/matchmaking/find")) return ok("{\"matched\":true,\"roomId\":1,\"instanceId\":1}");
    if (has(req, "POST /api/dorm/save")) return ok("{\"saved\":true,\"dormId\":1}");
    if (has(req, "GET /api/dorm/load")) return ok("{\"ownerId\":1,\"name\":\"My Dorm\",\"decorations\":[201]}");
    if (has(req, "POST /api/mod/kick")) return ok("{\"kicked\":true,\"userId\":99}");
    if (has(req, "POST /api/mod/mute")) return ok("{\"muted\":true,\"userId\":99}");

    if (has(req, "GET /api/inventory")) return ok("{\"items\":[{\"id\":101,\"name\":\"Starter Shirt\",\"equipped\":true},{\"id\":201,\"name\":\"Dorm Chair\",\"equipped\":false}]}");
    if (has(req, "POST /api/inventory/add")) return ok("{\"added\":true,\"itemId\":301,\"name\":\"New Item\"}");
    if (has(req, "POST /api/equip")) return ok("{\"equipped\":true,\"itemId\":101,\"slot\":\"shirt\"}");
    if (has(req, "POST /api/useConsumable")) return ok("{\"used\":true,\"item\":\"Root Beer\",\"remaining\":4}");
    if (has(req, "POST /api/buy")) return ok("{\"purchased\":true,\"itemId\":1,\"price\":250,\"tokensRemaining\":750}");
    if (has(req, "GET /api/party")) return ok("{\"partyId\":1,\"ownerId\":1,\"members\":[1]}");
    if (has(req, "POST /api/party/create")) return ok("{\"created\":true,\"partyId\":1}");
    if (has(req, "POST /api/party/join")) return ok("{\"joined\":true,\"partyId\":1,\"userId\":2}");
    if (has(req, "POST /api/presence/update")) return ok("{\"updated\":true,\"userId\":1,\"status\":\"online\"}");
    if (has(req, "GET /api/friends/online")) return ok("{\"onlineFriends\":[2,3,4]}");
    if (has(req, "GET /api/instances")) return ok("{\"instances\":[{\"id\":1,\"roomId\":1,\"players\":1,\"maxPlayers\":20}]}");
    if (has(req, "GET /api/feed")) return ok("{\"posts\":[{\"id\":1,\"userId\":1,\"text\":\"Welcome to RRServer\",\"likes\":0}]}");
    if (has(req, "POST /api/post")) return ok("{\"posted\":true,\"postId\":2}");
    if (has(req, "POST /api/comment")) return ok("{\"commented\":true,\"commentId\":1}");
    if (has(req, "POST /api/like")) return ok("{\"liked\":true,\"postId\":1}");
    if (has(req, "POST /api/rrplus/subscribe")) return ok("{\"subscribed\":true,\"monthlyTokens\":6000}");
    if (has(req, "POST /api/rrplus/cancel")) return ok("{\"cancelled\":true}");
    if (has(req, "GET /api/rrplus/perks")) return ok("{\"perks\":[\"monthly_tokens\",\"exclusive_items\",\"premium_dorm_themes\"]}");
    if (has(req, "GET /api/events")) return ok("{\"events\":[{\"id\":1,\"name\":\"Launch Event\",\"active\":true}]}");
    if (has(req, "GET /api/challenges")) return ok("{\"challenges\":[{\"id\":1,\"name\":\"Play 3 Rooms\",\"reward\":100}]}");
    if (has(req, "GET /api/dailymissions")) return ok("{\"missions\":[{\"id\":1,\"name\":\"Login Today\",\"completed\":false}]}");
    if (has(req, "POST /api/redeem")) return ok("{\"redeemed\":true,\"reward\":100}");
    if (has(req, "POST /api/uploadroom")) return ok("{\"uploaded\":true,\"roomId\":10}");
    if (has(req, "POST /api/uploadinvention")) return ok("{\"uploaded\":true,\"inventionId\":5}");
    if (has(req, "GET /api/workshop")) return ok("{\"items\":[{\"id\":1,\"name\":\"Starter Invention\",\"creatorId\":1}]}");
    if (has(req, "GET /api/workshop/trending")) return ok("{\"trending\":[{\"id\":1,\"name\":\"Trending Room\",\"visits\":100}]}");
    if (has(req, "POST /api/mod/ban")) return ok("{\"banned\":true,\"userId\":99}");
    if (has(req, "GET /api/mod/logs")) return ok("{\"logs\":[{\"id\":1,\"action\":\"seed_log\"}]}");

    if (has(req, "GET /api/instances")) return ok(InstanceManager::list());
    if (has(req, "POST /api/instances/create")) return ok(InstanceManager::create());
    if (has(req, "POST /api/cloudsave/save")) return ok(CloudSaveManager::save());
    if (has(req, "GET /api/cloudsave/load")) return ok(CloudSaveManager::load());
    if (has(req, "GET /api/equipment")) return ok(EquipmentManager::get());
    if (has(req, "POST /api/equipment/equip")) return ok(EquipmentManager::equip());
    if (has(req, "GET /api/quests/daily")) return ok(QuestManager::daily());
    if (has(req, "GET /api/quests/weekly")) return ok(QuestManager::weekly());
    if (has(req, "POST /api/quests/complete")) return ok(QuestManager::complete());
    if (has(req, "GET /api/admin/dashboard")) return ok(AdminManager::dashboard());

    if (has(req, "GET /api/staff/ranks")) return ok(StaffManager::ranks());
    if (has(req, "GET /api/staff/tag")) return ok(StaffManager::getTag());
    if (has(req, "POST /api/staff/tag/toggle")) return ok(StaffManager::toggleTag());
    if (has(req, "POST /api/staff/promote")) return ok(StaffManager::promote());
    if (has(req, "POST /api/staff/demote")) return ok(StaffManager::demote());
    if (has(req, "GET /api/live/heartbeat")) return ok(LiveManager::heartbeat());
    if (has(req, "GET /api/live/presence")) return ok(LiveManager::richPresence());
    if (has(req, "POST /api/live/room-event")) return ok(LiveManager::roomEvent());
    if (has(req, "GET /api/recnet/feed")) return ok(RecNetManager::feed());
    if (has(req, "GET /api/recnet/profile")) return ok(RecNetManager::profile());
    if (has(req, "POST /api/recnet/post")) return ok(RecNetManager::post());
    if (has(req, "POST /api/recnet/like")) return ok(RecNetManager::like());
    if (has(req, "POST /api/recnet/comment")) return ok(RecNetManager::comment());
    if (has(req, "GET /api/events/list")) return ok(EventManager::list());
    if (has(req, "POST /api/events/create")) return ok(EventManager::create());
    if (has(req, "POST /api/events/join")) return ok(EventManager::join());
    if (has(req, "GET /api/workshop/list")) return ok(WorkshopManager::list());
    if (has(req, "GET /api/workshop/trending")) return ok(WorkshopManager::trending());
    if (has(req, "POST /api/workshop/upload-room")) return ok(WorkshopManager::uploadRoom());
    if (has(req, "POST /api/workshop/upload-invention")) return ok(WorkshopManager::uploadInvention());

    if (has(req, "GET /api/analytics/summary")) return ok(AnalyticsManager::summary());
    if (has(req, "GET /api/analytics/players")) return ok(AnalyticsManager::players());
    if (has(req, "GET /api/analytics/economy")) return ok(AnalyticsManager::economy());
    if (has(req, "GET /api/security/audit")) return ok(SecurityManager::audit());
    if (has(req, "GET /api/security/ratelimit")) return ok(SecurityManager::rateLimit());
    if (has(req, "GET /api/security/integrity")) return ok(SecurityManager::integrity());
    if (has(req, "GET /api/cosmetics")) return ok(CosmeticsManager::list());
    if (has(req, "POST /api/cosmetics/equip")) return ok(CosmeticsManager::equip());
    if (has(req, "GET /api/announcements")) return ok(AnnouncementManager::list());
    if (has(req, "POST /api/announcements/create")) return ok(AnnouncementManager::create());

    if (has(req, "GET /api/matchmaking/queues")) return ok("{\"queues\":[{\"name\":\"paintball\",\"players\":6,\"maxPlayers\":8},{\"name\":\"rec_center\",\"players\":12,\"maxPlayers\":40}]}");
    if (has(req, "POST /api/matchmaking/join")) return ok("{\"joined\":true,\"queue\":\"rec_center\"}");
    if (has(req, "POST /api/matchmaking/leave")) return ok("{\"left\":true,\"queue\":\"rec_center\"}");
    if (has(req, "POST /api/matchmaking/start")) return ok("{\"started\":true,\"instanceId\":3,\"roomId\":2}");
    if (has(req, "GET /api/voice/channels")) return ok("{\"channels\":[{\"id\":1,\"roomId\":1,\"users\":[1]}]}");
    if (has(req, "POST /api/voice/create")) return ok("{\"created\":true,\"channelId\":2}");
    if (has(req, "POST /api/voice/join")) return ok("{\"joined\":true,\"channelId\":1,\"userId\":1}");
    if (has(req, "POST /api/voice/leave")) return ok("{\"left\":true,\"channelId\":1,\"userId\":1}");
    if (has(req, "POST /api/voice/mute")) return ok("{\"muted\":true,\"userId\":99}");
    if (has(req, "POST /api/clubs/create")) return ok("{\"created\":true,\"clubId\":2}");
    if (has(req, "POST /api/clubs/join")) return ok("{\"joined\":true,\"clubId\":1,\"userId\":1}");
    if (has(req, "POST /api/clubs/leave")) return ok("{\"left\":true,\"clubId\":1,\"userId\":1}");
    if (has(req, "POST /api/clubs/promote")) return ok("{\"promoted\":true,\"clubId\":1,\"userId\":2,\"role\":\"moderator\"}");
    if (has(req, "POST /api/clubs/kick")) return ok("{\"kicked\":true,\"clubId\":1,\"userId\":99}");
    if (has(req, "GET /api/economy")) return ok("{\"tokens\":1000,\"credits\":0,\"dailyAvailable\":true}");
    if (has(req, "POST /api/economy/earn")) return ok("{\"earned\":true,\"amount\":100,\"tokens\":1100}");
    if (has(req, "POST /api/economy/spend")) return ok("{\"spent\":true,\"amount\":250,\"tokens\":750}");
    if (has(req, "POST /api/economy/daily")) return ok("{\"claimed\":true,\"reward\":100}");
    if (has(req, "GET /api/admin/users")) return ok("{\"users\":[{\"id\":1,\"username\":\"test_user\",\"rank\":\"developer\"}]}");
    if (has(req, "GET /api/admin/rooms")) return ok("{\"rooms\":[{\"id\":1,\"name\":\"Dorm Room\"},{\"id\":2,\"name\":\"Rec Center\"}]}");
    if (has(req, "GET /api/admin/reports")) return ok("{\"reports\":[{\"id\":1,\"targetId\":99,\"status\":\"open\"}]}");
    if (has(req, "GET /api/admin/bans")) return ok("{\"bans\":[{\"id\":1,\"userId\":99,\"active\":true}]}");
    if (has(req, "POST /api/admin/broadcast")) return ok("{\"broadcasted\":true,\"message\":\"Server announcement sent\"}");
    if (has(req, "POST /api/admin/shutdown")) return ok("{\"shutdownQueued\":true}");
    if (has(req, "POST /api/mod/unban")) return ok("{\"unbanned\":true,\"userId\":99}");
    if (has(req, "POST /api/mod/warn")) return ok("{\"warned\":true,\"userId\":99,\"reason\":\"Test warning\"}");
    if (has(req, "GET /api/watch/staff-tag")) return ok("{\"userId\":1,\"rank\":\"Developer\",\"tagVisible\":true,\"title\":\"Developer\",\"colour\":\"#FFD700\",\"icon\":\"hammer\"}");
    if (has(req, "POST /api/watch/staff-tag/toggle")) return ok("{\"updated\":true,\"tagVisible\":false}");

    if (has(req, "GET /api/rich-presence")) return ok(FinalSystems::richPresence());
    if (has(req, "GET /api/nameplate")) return ok(FinalSystems::nameplate());
    if (has(req, "GET /api/dorm/editor")) return ok(FinalSystems::dormEditor());
    if (has(req, "GET /api/mod/actions")) return ok(FinalSystems::moderationActions());
    if (has(req, "GET /api/economy/rewards")) return ok(FinalSystems::economyRewards());
    if (has(req, "GET /api/rrplus/full")) return ok(FinalSystems::rrplusPerks());
    if (has(req, "GET /api/matchmaking/modes")) return ok(FinalSystems::matchmakingModes());
    if (has(req, "GET /api/watch/config")) return ok(FinalSystems::watchConfig());

    if (has(req, "GET /api/v1/moderation")) return ok(V1Systems::moderationV2());
    if (has(req, "GET /api/v1/appeals")) return ok(V1Systems::appeals());
    if (has(req, "GET /api/v1/party")) return ok(V1Systems::partyV2());
    if (has(req, "GET /api/v1/economy")) return ok(V1Systems::economyV2());
    if (has(req, "GET /api/v1/outfits")) return ok(V1Systems::outfits());
    if (has(req, "GET /api/v1/dorm-permissions")) return ok(V1Systems::dormPermissions());
    if (has(req, "GET /api/v1/voice-moderation")) return ok(V1Systems::voiceModeration());
    if (has(req, "GET /api/v1/clubs")) return ok(V1Systems::clubV2());
    if (has(req, "GET /api/v1/notifications")) return ok(V1Systems::notificationsV2());
    if (has(req, "GET /api/v1/security")) return ok(V1Systems::securityV2());
    if (has(req, "GET /api/v1/admin-capabilities")) return ok(V1Systems::adminCapabilities());
    if (has(req, "GET /api/v1/watch")) return ok(V1Systems::watchSystem());

    if (has(req, "GET /api/gameplay/circuits")) return ok(GameplayPack::circuits());
    if (has(req, "POST /api/gameplay/circuits/save")) return ok("{\"saved\":true,\"circuitId\":1}");
    if (has(req, "POST /api/gameplay/circuits/load")) return ok(GameplayPack::circuits());
    if (has(req, "POST /api/gameplay/circuits/compile")) return ok("{\"compiled\":true,\"errors\":0}");
    if (has(req, "GET /api/inventions")) return ok(GameplayPack::inventions());
    if (has(req, "POST /api/inventions/upload")) return ok("{\"uploaded\":true,\"inventionId\":501}");
    if (has(req, "POST /api/inventions/download")) return ok("{\"downloaded\":true,\"inventionId\":1}");
    if (has(req, "POST /api/inventions/rate")) return ok("{\"rated\":true,\"rating\":5}");
    if (has(req, "POST /api/inventions/comment")) return ok("{\"commented\":true,\"commentId\":1}");
    if (has(req, "GET /api/makerpen")) return ok(GameplayPack::makerpen());
    if (has(req, "POST /api/makerpen/spawn")) return ok("{\"spawned\":true,\"objectId\":1}");
    if (has(req, "POST /api/makerpen/delete")) return ok("{\"deleted\":true,\"objectId\":1}");
    if (has(req, "POST /api/makerpen/move")) return ok("{\"moved\":true,\"objectId\":1}");
    if (has(req, "POST /api/makerpen/undo")) return ok("{\"undo\":true}");
    if (has(req, "POST /api/makerpen/redo")) return ok("{\"redo\":true}");
    if (has(req, "GET /api/games/paintball")) return ok(GameplayPack::paintball());
    if (has(req, "GET /api/games/lasertag")) return ok(GameplayPack::lasertag());
    if (has(req, "GET /api/games/bowling")) return ok(GameplayPack::bowling());
    if (has(req, "GET /api/games/charades")) return ok(GameplayPack::charades());
    if (has(req, "GET /api/games/dodgeball")) return ok(GameplayPack::dodgeball());
    if (has(req, "GET /api/npcs")) return ok(GameplayPack::npcs());
    if (has(req, "POST /api/teleport/player")) return ok("{\"teleported\":true,\"target\":\"player\"}");
    if (has(req, "POST /api/teleport/room")) return ok("{\"teleported\":true,\"target\":\"room\"}");
    if (has(req, "POST /api/teleport/instance")) return ok("{\"teleported\":true,\"target\":\"instance\"}");
    if (has(req, "GET /api/live/seasons")) return ok(GameplayPack::seasons());
    if (has(req, "GET /api/developer")) return ok(GameplayPack::developer());

    if (has(req, "GET /api/launch/progression")) return ok(LaunchPack::progression());
    if (has(req, "GET /api/launch/moderation-center")) return ok(LaunchPack::moderationCenter());
    if (has(req, "GET /api/launch/staff-ranks")) return ok(LaunchPack::staffRanks());
    if (has(req, "GET /api/launch/rooms-v2")) return ok(LaunchPack::roomsV2());
    if (has(req, "GET /api/launch/npc-v2")) return ok(LaunchPack::npcV2());
    if (has(req, "GET /api/launch/economy-v3")) return ok(LaunchPack::economyV3());
    if (has(req, "GET /api/launch/recnet-v2")) return ok(LaunchPack::recnetV2());
    if (has(req, "GET /api/launch/clubs-v3")) return ok(LaunchPack::clubsV3());
    if (has(req, "GET /api/launch/voice-v2")) return ok(LaunchPack::voiceV2());
    if (has(req, "GET /api/launch/security-v3")) return ok(LaunchPack::securityV3());
    if (has(req, "GET /api/launch/universe")) return ok(LaunchPack::universe());

    if (has(req, "GET /api/backend2/matchmaking")) return ok(Backend2::matchmakingV2());
    if (has(req, "GET /api/backend2/parties")) return ok(Backend2::partiesV3());
    if (has(req, "GET /api/backend2/dorms")) return ok(Backend2::dormsV3());
    if (has(req, "GET /api/backend2/assets")) return ok(Backend2::assetsV2());
    if (has(req, "GET /api/backend2/inventory")) return ok(Backend2::inventoryV2());
    if (has(req, "GET /api/backend2/gifts")) return ok(Backend2::giftsV2());
    if (has(req, "GET /api/backend2/presence")) return ok(Backend2::presenceV2());
    if (has(req, "GET /api/backend2/creator-economy")) return ok(Backend2::creatorEconomy());
    if (has(req, "GET /api/backend2/watch")) return ok(Backend2::watchSupport());
    if (has(req, "GET /api/backend2/staff-permissions")) return ok(Backend2::staffPermissions());
    if (has(req, "GET /api/backend2/anticheat")) return ok(Backend2::anticheatV4());
    if (has(req, "GET /api/backend2/status")) return ok(Backend2::status());

    if (has(req, "GET /api/backend3/multiplayer")) return ok(Backend3::multiplayer());
    if (has(req, "GET /api/backend3/circuits")) return ok(Backend3::circuitsV3());
    if (has(req, "GET /api/backend3/makerpen")) return ok(Backend3::makerpenV2());
    if (has(req, "GET /api/backend3/economy")) return ok(Backend3::economyV4());
    if (has(req, "GET /api/backend3/recnet")) return ok(Backend3::recnetV3());
    if (has(req, "GET /api/backend3/moderation")) return ok(Backend3::moderationV3());
    if (has(req, "GET /api/backend3/npcs")) return ok(Backend3::npcsV3());
    if (has(req, "GET /api/backend3/live-events")) return ok(Backend3::liveEventsV2());
    if (has(req, "GET /api/backend3/anticheat")) return ok(Backend3::anticheatV5());
    if (has(req, "GET /api/backend3/platform")) return ok(Backend3::platform());

    if (has(req, "GET /api/backend4/status")) return ok(Backend4::status());
    if (has(req, "GET /api/backend4/health")) return ok(Backend4::health());
    if (has(req, "GET /api/backend4/api-map")) return ok(Backend4::apiMap());
    if (has(req, "GET /api/backend4/production")) return ok(Backend4::production());
    if (has(req, "GET /api/backend4/realtime")) return ok(Backend4::realtime());
    if (has(req, "GET /api/backend4/persistence")) return ok(Backend4::persistence());
    if (has(req, "GET /api/backend4/deployment")) return ok(Backend4::deployment());
    if (has(req, "GET /api/backend4/diagnostics")) return ok(Backend4::diagnostics());

    return notFound();
}

void HttpServer::start(int port) {
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) {
        std::cout << "Failed to create socket." << std::endl;
        return;
    }

    int opt = 1;
    setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(serverFd, (sockaddr*)&address, sizeof(address)) < 0) {
        std::cout << "Failed to bind HTTP server." << std::endl;
        close(serverFd);
        return;
    }

    listen(serverFd, 10);

    std::cout << "HTTP server running on port " << port << std::endl;
    std::cout << "Open: http://127.0.0.1:" << port << "/api/status" << std::endl;

    while (true) {
        int client = accept(serverFd, nullptr, nullptr);
        if (client < 0) continue;

        char buffer[8192] = {0};
        read(client, buffer, 8192);

        std::string req(buffer);
        std::string res = route(req);

        send(client, res.c_str(), res.size(), 0);
        close(client);
    }
}
