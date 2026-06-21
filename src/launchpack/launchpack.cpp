#include "launchpack.h"

std::string LaunchPack::progression() {
    return "{\"levels\":true,\"xp\":true,\"titles\":true,\"badges\":true,\"weeklyChallenges\":true,\"careerStats\":true}";
}

std::string LaunchPack::moderationCenter() {
    return "{\"moderatorNotes\":true,\"caseSystem\":true,\"evidenceStorage\":true,\"appealVoting\":true,\"muteSystem\":true,\"kickSystem\":true,\"shadowBan\":true}";
}

std::string LaunchPack::staffRanks() {
    return "{\"ranks\":[\"volunteer_moderator\",\"community_team\",\"developer\",\"senior_developer\",\"administrator\",\"head_moderator\",\"head_developer\",\"owner\"],\"tagColor\":\"#00FFFF\",\"showTag\":true}";
}

std::string LaunchPack::roomsV2() {
    return "{\"roomPermissions\":true,\"subrooms\":true,\"roomTemplates\":true,\"spawnpoints\":true,\"cloning\":true,\"publishing\":true}";
}

std::string LaunchPack::npcV2() {
    return "{\"conversationNPC\":true,\"questNPC\":true,\"vendorNPC\":true,\"guideNPC\":true,\"npcBrain\":true}";
}

std::string LaunchPack::economyV3() {
    return "{\"tokens\":true,\"food\":true,\"drinks\":true,\"skins\":true,\"boxes\":true,\"consumables\":true,\"tradingTax\":true,\"limitedItems\":true,\"dailyLoginRewards\":true,\"wheelSpins\":true}";
}

std::string LaunchPack::recnetV2() {
    return "{\"followers\":true,\"likes\":true,\"comments\":true,\"posts\":true,\"videos\":true,\"images\":true,\"subscriptions\":true,\"trending\":true}";
}

std::string LaunchPack::clubsV3() {
    return "{\"clubRoles\":true,\"clubEvents\":true,\"clubAnnouncements\":true,\"clubEconomy\":true,\"clubChat\":true,\"clubVoiceChannels\":true}";
}

std::string LaunchPack::voiceV2() {
    return "{\"spatialVoice\":true,\"privateCalls\":true,\"pushToTalk\":true,\"noiseSuppression\":true,\"recording\":true,\"voiceReports\":true,\"voiceBans\":true}";
}

std::string LaunchPack::securityV3() {
    return "{\"antiCheat\":true,\"integrityChecks\":true,\"packetValidation\":true,\"speedChecks\":true,\"flyChecks\":true,\"banEvasion\":true}";
}

std::string LaunchPack::universe() {
    return "{\"universeService\":true,\"gameCoordinator\":true,\"photonBridge\":true,\"assetCDN\":true,\"liveEvents\":true,\"roomAuthority\":true,\"playerAuthority\":true,\"presenceCoordinator\":true,\"questEngine\":true,\"xpService\":true,\"seasonPass\":true,\"moderationCenter\":true,\"circuitCompiler\":true,\"makerPenAuthority\":true,\"npcBrain\":true,\"backend\":\"1.0-ready\"}";
}
