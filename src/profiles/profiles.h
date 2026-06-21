#pragma once
#include <string>
#include <vector>

struct Profile {
    int userId;
    std::string displayName;
    std::string bio;
    int level;
    int xp;
};

class ProfileManager {
public:
    static Profile createProfile(int userId, const std::string& displayName);
    static Profile* getProfile(int userId);
    static int count();
};
