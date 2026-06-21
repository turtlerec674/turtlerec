#include "recnet.h"

std::string RecNetManager::feed() {
    return "{\"posts\":[{\"id\":1,\"userId\":1,\"text\":\"Welcome to the backend\",\"likes\":12}]}";
}

std::string RecNetManager::profile() {
    return "{\"userId\":1,\"username\":\"test_user\",\"displayName\":\"Roxy\",\"followers\":10,\"verified\":true}";
}

std::string RecNetManager::post() {
    return "{\"posted\":true,\"postId\":2}";
}

std::string RecNetManager::like() {
    return "{\"liked\":true,\"postId\":1}";
}

std::string RecNetManager::comment() {
    return "{\"commented\":true,\"commentId\":1}";
}
