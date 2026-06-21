#include "avatar.h"

static std::vector<Avatar> avatars;

Avatar AvatarManager::createAvatar(int userId) {
    Avatar avatar{userId, 0, 0, 0, 0};
    avatars.push_back(avatar);
    return avatar;
}

Avatar* AvatarManager::getAvatar(int userId) {
    for (auto& a : avatars) {
        if (a.userId == userId) return &a;
    }

    return nullptr;
}

bool AvatarManager::equipItem(int userId, const std::string& slot, int itemId) {
    Avatar* avatar = getAvatar(userId);
    if (!avatar) return false;

    if (slot == "shirt") avatar->shirt = itemId;
    else if (slot == "hat") avatar->hat = itemId;
    else if (slot == "gloves") avatar->gloves = itemId;
    else if (slot == "hair") avatar->hair = itemId;
    else return false;

    return true;
}

int AvatarManager::count() {
    return avatars.size();
}
