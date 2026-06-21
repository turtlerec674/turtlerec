#include "admin.h"
std::string AdminManager::dashboard() {
    return "{\"admin\":true,\"status\":\"online\",\"moderationQueue\":1,\"reports\":1,\"bans\":1}";
}
