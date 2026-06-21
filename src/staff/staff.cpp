#include "staff.h"

std::string StaffManager::ranks() {
    return "{\"ranks\":[\"player\",\"volunteer_mod\",\"community_team\",\"developer\",\"admin\",\"owner\"]}";
}

std::string StaffManager::getTag() {
    return "{\"userId\":1,\"enabled\":true,\"rank\":\"developer\",\"title\":\"Developer\",\"colour\":\"#FFD700\",\"icon\":\"hammer\"}";
}

std::string StaffManager::toggleTag() {
    return "{\"updated\":true,\"userId\":1,\"tagEnabled\":false}";
}

std::string StaffManager::promote() {
    return "{\"promoted\":true,\"userId\":2,\"rank\":\"volunteer_mod\"}";
}

std::string StaffManager::demote() {
    return "{\"demoted\":true,\"userId\":2,\"rank\":\"player\"}";
}
