#include "backend3.h"

std::string Backend3::multiplayer() {
    return "{\"worldPersistence\":true,\"roomInstancesV3\":true,\"subroomAuthority\":true,\"dormAuthority\":true,\"objectOwnership\":true,\"netTransform\":true,\"photonCompatibility\":true,\"voiceSpatialization\":true}";
}

std::string Backend3::circuitsV3() {
    return "{\"circuitsV3\":true,\"chipExecution\":true,\"wireReplication\":true,\"eventDispatcher\":true,\"circuitCompilerV2\":true,\"cloudVariables\":true,\"persistentBoards\":true}";
}

std::string Backend3::makerpenV2() {
    return "{\"makerPenV2\":true,\"shapeTool\":true,\"cloneTool\":true,\"selectionTool\":true,\"materialLibrary\":true,\"prefabService\":true,\"blueprintStorage\":true}";
}

std::string Backend3::economyV4() {
    return "{\"tokenService\":true,\"microtransactions\":true,\"subscriptions\":true,\"creatorPayouts\":true,\"featuredRooms\":true,\"giftBoxes\":true,\"dailyChallenges\":true}";
}

std::string Backend3::recnetV3() {
    return "{\"profiles\":true,\"feed\":true,\"comments\":true,\"likes\":true,\"portfolioService\":true,\"imageUploads\":true,\"videoEmbeds\":true}";
}

std::string Backend3::moderationV3() {
    return "{\"trustSafety\":true,\"voiceReports\":true,\"playerReports\":true,\"appealsV2\":true,\"banEvasion\":true,\"altDetection\":true,\"deviceFingerprint\":true}";
}

std::string Backend3::npcsV3() {
    return "{\"npcNavigation\":true,\"npcDialogue\":true,\"npcSchedules\":true,\"npcCombat\":true,\"petSystem\":true,\"companions\":true}";
}

std::string Backend3::liveEventsV2() {
    return "{\"liveEvents\":true,\"concertManager\":true,\"fireworks\":true,\"stageControls\":true,\"crowdSimulation\":true}";
}

std::string Backend3::anticheatV5() {
    return "{\"movementChecks\":true,\"flyChecks\":true,\"teleportChecks\":true,\"economyChecks\":true,\"circuitExploitChecks\":true,\"dormCrashChecks\":true,\"voiceSpamChecks\":true,\"assetValidation\":true,\"packetInspection\":true,\"watchdog\":true}";
}

std::string Backend3::platform() {
    return "{\"backendVersion\":\"3.0\",\"status\":\"ONLINE\",\"universeService\":true,\"multiverseService\":true,\"dedicatedServers\":true,\"ugcMarketplace\":true,\"rrplusV2\":true,\"cloudSyncV2\":true,\"crossPlatformPresence\":true,\"avatarExpressions\":true,\"handTracking\":true,\"bodyTracking\":true,\"dynamicLighting\":true,\"weatherSystem\":true,\"seasonPassV2\":true,\"partyGames\":true,\"dormPortals\":true,\"guildSystem\":true,\"clanWars\":true,\"competitiveRanked\":true,\"creatorStudio\":true,\"assetStreaming\":true}";
}
