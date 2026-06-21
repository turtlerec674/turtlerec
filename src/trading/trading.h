#pragma once
#include <string>
#include <vector>

struct Trade {
    int id;
    int fromUserId;
    int toUserId;
    int itemId;
    std::string status;
};

class TradeManager {
public:
    static Trade createTrade(int fromUserId, int toUserId, int itemId);
    static bool acceptTrade(int tradeId);
    static int count();
};
