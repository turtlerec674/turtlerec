#pragma once
#include <vector>

struct Purchase {
    int id;
    int userId;
    int itemId;
    int price;
};

class PurchaseManager {
public:
    static Purchase createPurchase(int userId, int itemId, int price);
    static int count();
};
