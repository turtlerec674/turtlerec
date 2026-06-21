#include "instances.h"
std::string InstanceManager::list() {
    return "{\"instances\":[{\"id\":1,\"roomId\":1,\"players\":1,\"maxPlayers\":20,\"type\":\"public\"}]}";
}
std::string InstanceManager::create() {
    return "{\"created\":true,\"instanceId\":2,\"roomId\":1}";
}
