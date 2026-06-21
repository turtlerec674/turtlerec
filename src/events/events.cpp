#include "events.h"

std::string EventManager::list() {
    return "{\"events\":[{\"id\":1,\"name\":\"Launch Event\",\"active\":true,\"roomId\":1}]}";
}

std::string EventManager::create() {
    return "{\"created\":true,\"eventId\":2}";
}

std::string EventManager::join() {
    return "{\"joined\":true,\"eventId\":1,\"userId\":1}";
}
