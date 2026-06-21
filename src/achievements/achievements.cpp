#include "achievements.h"

static std::vector<Achievement> achievements;
static int nextAchievementId = 1;

Achievement AchievementManager::unlock(int userId, const std::string& name) {
    Achievement achievement{nextAchievementId++, userId, name};
    achievements.push_back(achievement);
    return achievement;
}

int AchievementManager::count() {
    return achievements.size();
}
