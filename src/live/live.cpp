#include "live.h"

std::string LiveManager::heartbeat() {
    return "{\"heartbeat\":true,\"server\":\"online\"}";
}

std::string LiveManager::richPresence() {
    return "{\"userId\":1,\"status\":\"in_room\",\"roomId\":1,\"partyId\":1}";
}

std::string LiveManager::roomEvent() {
    return "{\"event\":\"room_joined\",\"userId\":1,\"roomId\":1}";
}
