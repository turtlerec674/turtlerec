#pragma once
#include <string>

class AssetManager {
public:
    static std::string uploadPhoto(int userId);
    static std::string uploadAvatar(int userId);
};
