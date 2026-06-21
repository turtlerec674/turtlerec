#include "backend2.h"

std::string Backend2::matchmakingV2() {
    return "{\"competitive\":true,\"casual\":true,\"privateInstances\":true,\"quickPlay\":true,\"skillRatings\":true}";
}

std::string Backend2::partiesV3() {
    return "{\"partyInvites\":true,\"partyVoice\":true,\"partyTravel\":true,\"partyPermissions\":true,\"leaderTransfer\":true}";
}

std::string Backend2::dormsV3() {
    return "{\"dormPermissions\":true,\"dormVisitors\":true,\"dormEditors\":true,\"dormThemes\":true,\"saveSlots\":5}";
}

std::string Backend2::assetsV2() {
    return "{\"assetBundles\":true,\"cdn\":true,\"textureCache\":true,\"audioCache\":true,\"meshStreaming\":true}";
}

std::string Backend2::inventoryV2() {
    return "{\"consumables\":true,\"equipment\":true,\"backpacks\":true,\"food\":true,\"drinks\":true,\"limitedItems\":true}";
}

std::string Backend2::giftsV2() {
    return "{\"giftInventory\":true,\"giftHistory\":true,\"giftTrading\":true,\"giftReceipts\":true}";
}

std::string Backend2::presenceV2() {
    return "{\"lastSeen\":true,\"statusMessages\":true,\"joinableSessions\":true,\"activityFeed\":true}";
}

std::string Backend2::creatorEconomy() {
    return "{\"creatorPayments\":true,\"revenueSharing\":true,\"premiumRooms\":true,\"creatorAnalytics\":true,\"tips\":true}";
}

std::string Backend2::watchSupport() {
    return "{\"watchPresence\":true,\"watchNotifications\":true,\"watchVoice\":true,\"watchInvites\":true,\"watchParty\":true}";
}

std::string Backend2::staffPermissions() {
    return "{\"ranks\":[\"volunteer_moderator\",\"community_team\",\"developer\",\"senior_developer\",\"administrator\",\"head_moderator\",\"head_developer\",\"owner\"],\"permissions\":{\"ban\":true,\"mute\":true,\"kick\":true,\"teleport\":true,\"godmode\":true,\"invisible\":true,\"spawnitems\":true,\"editrooms\":true}}";
}

std::string Backend2::anticheatV4() {
    return "{\"movementChecks\":true,\"flyChecks\":true,\"teleportChecks\":true,\"packetChecks\":true,\"roomAuthorityChecks\":true,\"economyChecks\":true,\"cloudSaveChecks\":true,\"banEvasion\":true}";
}

std::string Backend2::status() {
    return "{\"backendVersion\":\"2.0\",\"status\":\"ONLINE\",\"build\":\"Alpha\",\"httpPort\":3000}";
}
