#include "profiles.h"

static std::vector<Profile> profiles;

Profile ProfileManager::createProfile(int userId, const std::string& displayName) {
    Profile profile{userId, displayName, "", 1, 0};
    profiles.push_back(profile);
    return profile;
}

Profile* ProfileManager::getProfile(int userId) {
    for (auto& p : profiles) {
        if (p.userId == userId) return &p;
    }

    return nullptr;
}

int ProfileManager::count() {
    return profiles.size();
}
