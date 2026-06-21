#pragma once
#include <vector>

struct BlockEntry {
    int userId;
    int blockedUserId;
};

class BlocklistManager {
public:
    static bool blockUser(int userId, int blockedUserId);
    static bool isBlocked(int userId, int targetId);
    static int count();
};
