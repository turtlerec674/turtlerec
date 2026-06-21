#include "workshop.h"

std::string WorkshopManager::list() {
    return "{\"items\":[{\"id\":1,\"name\":\"Starter Invention\",\"creatorId\":1}]}";
}

std::string WorkshopManager::trending() {
    return "{\"trending\":[{\"id\":1,\"name\":\"Trending Room\",\"visits\":100}]}";
}

std::string WorkshopManager::uploadRoom() {
    return "{\"uploaded\":true,\"roomId\":10}";
}

std::string WorkshopManager::uploadInvention() {
    return "{\"uploaded\":true,\"inventionId\":5}";
}
