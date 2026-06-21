#include "security.h"

std::string SecurityManager::audit() {
    return "{\"auditLogs\":[{\"id\":1,\"action\":\"server_started\"}]}";
}

std::string SecurityManager::rateLimit() {
    return "{\"rateLimit\":true,\"maxRequestsPerMinute\":120}";
}

std::string SecurityManager::integrity() {
    return "{\"integrity\":\"ok\",\"antiTamper\":true}";
}
