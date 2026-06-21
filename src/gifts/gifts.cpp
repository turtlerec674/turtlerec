#include "gifts.h"

static std::vector<Gift> gifts;
static int nextGiftId = 1;

Gift GiftManager::sendGift(int fromUserId, int toUserId, int itemId) {
    Gift gift{nextGiftId++, fromUserId, toUserId, itemId, false};
    gifts.push_back(gift);
    return gift;
}

bool GiftManager::claimGift(int giftId) {
    for (auto& g : gifts) {
        if (g.id == giftId) {
            g.claimed = true;
            return true;
        }
    }
    return false;
}

int GiftManager::count() {
    return gifts.size();
}
