#pragma once
#include <string>
#include <vector>

struct Achievement {
    int id;
    int userId;
    std::string name;
};

class AchievementManager {
public:
    static Achievement unlock(int userId, const std::string& name);
    static int count();
};
