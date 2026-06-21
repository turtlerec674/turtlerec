#include "leaderboards.h"
#include <algorithm>

static std::vector<LeaderboardEntry> scores;

LeaderboardEntry LeaderboardManager::submitScore(int userId, int score) {
    for (auto& s : scores) {
        if (s.userId == userId) {
            if (score > s.score) s.score = score;
            return s;
        }
    }

    LeaderboardEntry entry{userId, score};
    scores.push_back(entry);
    return entry;
}

std::vector<LeaderboardEntry> LeaderboardManager::getTop() {
    std::sort(scores.begin(), scores.end(), [](auto& a, auto& b) {
        return a.score > b.score;
    });

    return scores;
}

int LeaderboardManager::count() {
    return scores.size();
}
