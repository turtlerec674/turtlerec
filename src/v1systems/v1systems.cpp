#include "v1systems.h"

std::string V1Systems::moderationV2() {
    return "{\"warnings\":1,\"appeals\":1,\"kickHistory\":1,\"banHistory\":1,\"ipBans\":0,\"hwidBans\":0,\"muteHistory\":1,\"moderatorNotes\":1,\"cases\":1,\"evidence\":1}";
}

std::string V1Systems::appeals() {
    return "{\"appeals\":[{\"id\":1,\"userId\":99,\"status\":\"open\",\"reason\":\"Ban appeal\"}]}";
}

std::string V1Systems::partyV2() {
    return "{\"partyId\":1,\"leaderId\":1,\"privacy\":\"friends_only\",\"voiceChannel\":1,\"ready\":[1],\"invites\":[2,3]}";
}

std::string V1Systems::economyV2() {
    return "{\"daily\":100,\"weekly\":750,\"monthly\":2500,\"loginStreak\":3,\"giftBoxes\":1,\"tokenGrants\":1,\"seasonPass\":false}";
}

std::string V1Systems::outfits() {
    return "{\"slots\":25,\"favoriteSlot\":1,\"outfits\":[{\"slot\":1,\"name\":\"Default\",\"items\":[101,102,103]}]}";
}

std::string V1Systems::dormPermissions() {
    return "{\"owner\":1,\"coOwners\":[2],\"editors\":[3],\"decorators\":[4],\"visitors\":[5],\"banned\":[99]}";
}

std::string V1Systems::voiceModeration() {
    return "{\"voiceMute\":false,\"pushToTalk\":true,\"reports\":1,\"spatialAudio\":true,\"recordingLogs\":1,\"volumeLimit\":100}";
}

std::string V1Systems::clubV2() {
    return "{\"clubId\":1,\"roles\":[\"owner\",\"moderator\",\"member\"],\"treasury\":1000,\"events\":1,\"banner\":\"club_banner.png\",\"icon\":\"club_icon.png\",\"announcements\":1,\"applications\":1}";
}

std::string V1Systems::notificationsV2() {
    return "{\"notifications\":[\"friend_request\",\"party_invite\",\"dorm_invite\",\"club_invite\",\"gift_received\",\"quest_completed\",\"achievement_unlocked\"]}";
}

std::string V1Systems::securityV2() {
    return "{\"jwt\":true,\"refreshTokens\":true,\"sessionExpiry\":true,\"altDetection\":true,\"vpnDetection\":false,\"rateLimiting\":true,\"apiKeys\":true,\"adminAuth\":true}";
}

std::string V1Systems::adminCapabilities() {
    return "{\"ranks\":[\"volunteer_moderator\",\"moderator\",\"senior_moderator\",\"community_team\",\"junior_developer\",\"developer\",\"senior_developer\",\"lead_developer\",\"administrator\",\"owner\"],\"capabilities\":[\"kick_users\",\"ban_users\",\"mute_users\",\"teleport\",\"spawn_items\",\"grant_tokens\",\"grant_cosmetics\",\"view_logs\",\"manage_events\",\"broadcast_announcements\",\"shutdown_instances\"]}";
}

std::string V1Systems::watchSystem() {
    return "{\"showTag\":true,\"showRank\":true,\"showLevel\":true,\"showPlatform\":true,\"showStatus\":true,\"badges\":[\"rrplus\",\"developer\",\"moderator\",\"community_team\",\"owner\"]}";
}
