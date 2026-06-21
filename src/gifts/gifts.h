#pragma once
#include <string>
#include <vector>

struct Gift {
    int id;
    int fromUserId;
    int toUserId;
    int itemId;
    bool claimed;
};

class GiftManager {
public:
    static Gift sendGift(int fromUserId, int toUserId, int itemId);
    static bool claimGift(int giftId);
    static int count();
};
