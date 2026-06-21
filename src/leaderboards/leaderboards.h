#pragma once
#include <vector>

struct LeaderboardEntry {
    int userId;
    int score;
};

class LeaderboardManager {
public:
    static LeaderboardEntry submitScore(int userId, int score);
    static std::vector<LeaderboardEntry> getTop();
    static int count();
};
