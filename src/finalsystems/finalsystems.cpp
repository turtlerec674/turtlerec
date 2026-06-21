#include "finalsystems.h"

std::string FinalSystems::richPresence() {
    return "{\"userId\":1,\"status\":\"playing\",\"roomId\":2,\"roomName\":\"Rec Center\",\"instanceId\":3,\"partyId\":1,\"joinable\":true,\"platform\":\"Quest\",\"device\":\"Standalone VR\"}";
}

std::string FinalSystems::nameplate() {
    return "{\"userId\":1,\"enabled\":true,\"rank\":\"Developer\",\"title\":\"Developer\",\"colour\":\"#55AAFF\",\"icon\":\"hammer\",\"showBadge\":true,\"showWatchNameplate\":true}";
}

std::string FinalSystems::dormEditor() {
    return "{\"dormId\":1,\"objects\":[{\"id\":201,\"name\":\"Chair\",\"x\":1.2,\"y\":0,\"z\":-2.4,\"rotY\":90}],\"permissions\":\"owner\"}";
}

std::string FinalSystems::moderationActions() {
    return "{\"actions\":[\"kick\",\"ban\",\"mute\",\"warn\",\"timeout\",\"suspend\",\"shadow_mute\",\"voice_mute\",\"dorm_reset\",\"inventory_wipe\",\"token_rollback\"]}";
}

std::string FinalSystems::economyRewards() {
    return "{\"daily\":100,\"weekly\":750,\"loginStreak\":3,\"giftBoxes\":1,\"seasonReward\":\"Starter Box\"}";
}

std::string FinalSystems::rrplusPerks() {
    return "{\"active\":true,\"monthlyTokens\":6000,\"perks\":[\"monthly_box\",\"exclusive_cosmetics\",\"custom_dorm_themes\",\"extra_outfit_slots\",\"animated_nameplates\",\"exclusive_events\"]}";
}

std::string FinalSystems::matchmakingModes() {
    return "{\"modes\":[\"rec_center\",\"dorm\",\"paintball\",\"laser_tag\",\"bowling\",\"custom_rooms\",\"private_rooms\",\"friends_only\",\"invite_only\",\"public\"]}";
}

std::string FinalSystems::watchConfig() {
    return "{\"userId\":1,\"showTag\":true,\"showRank\":true,\"showPlatform\":true,\"showLevel\":true,\"watchStaffControls\":true}";
}
