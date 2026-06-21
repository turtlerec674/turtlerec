#include "blocklist.h"

static std::vector<BlockEntry> blocks;

bool BlocklistManager::blockUser(int userId, int blockedUserId) {
    blocks.push_back({userId, blockedUserId});
    return true;
}

bool BlocklistManager::isBlocked(int userId, int targetId) {
    for (auto& b : blocks) {
        if (b.userId == userId && b.blockedUserId == targetId) return true;
    }
    return false;
}

int BlocklistManager::count() {
    return blocks.size();
}
