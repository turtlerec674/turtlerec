#include "purchases.h"

static std::vector<Purchase> purchases;
static int nextPurchaseId = 1;

Purchase PurchaseManager::createPurchase(int userId, int itemId, int price) {
    Purchase purchase{nextPurchaseId++, userId, itemId, price};
    purchases.push_back(purchase);
    return purchase;
}

int PurchaseManager::count() {
    return purchases.size();
}
