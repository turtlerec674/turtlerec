#include "trading.h"

static std::vector<Trade> trades;
static int nextTradeId = 1;

Trade TradeManager::createTrade(int fromUserId, int toUserId, int itemId) {
    Trade trade{nextTradeId++, fromUserId, toUserId, itemId, "pending"};
    trades.push_back(trade);
    return trade;
}

bool TradeManager::acceptTrade(int tradeId) {
    for (auto& t : trades) {
        if (t.id == tradeId) {
            t.status = "accepted";
            return true;
        }
    }
    return false;
}

int TradeManager::count() {
    return trades.size();
}
