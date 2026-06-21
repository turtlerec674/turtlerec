#include "bans.h"

static std::vector<Ban> bans;
static int nextBanId = 1;

Ban BanManager::banUser(int userId, const std::string& reason) {
    Ban ban{nextBanId++, userId, reason, true};
    bans.push_back(ban);
    return ban;
}

bool BanManager::isBanned(int userId) {
    for (auto& b : bans) {
        if (b.userId == userId && b.active) return true;
    }
    return false;
}

int BanManager::count() {
    return bans.size();
}
