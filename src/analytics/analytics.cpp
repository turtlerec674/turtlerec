#include "analytics.h"

std::string AnalyticsManager::summary() {
    return "{\"playersOnline\":1,\"roomsActive\":2,\"reportsOpen\":1,\"tokensSpent\":250}";
}

std::string AnalyticsManager::players() {
    return "{\"dailyActiveUsers\":1,\"concurrentPlayers\":1,\"newUsers\":1}";
}

std::string AnalyticsManager::economy() {
    return "{\"tokensMinted\":1000,\"tokensSpent\":250,\"purchases\":1}";
}
