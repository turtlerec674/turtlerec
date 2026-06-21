#include "assets.h"

std::string AssetManager::uploadPhoto(int userId) {
    return "{\"uploaded\":true,\"type\":\"photo\",\"userId\":" + std::to_string(userId) + "}";
}

std::string AssetManager::uploadAvatar(int userId) {
    return "{\"uploaded\":true,\"type\":\"avatar\",\"userId\":" + std::to_string(userId) + "}";
}
