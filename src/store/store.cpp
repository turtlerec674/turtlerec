#include "store.h"

static std::vector<StoreItem> storeItems;
static int nextStoreItemId = 1;

StoreItem StoreManager::addStoreItem(const std::string& name, int price, const std::string& category) {
    StoreItem item{nextStoreItemId++, name, price, category};
    storeItems.push_back(item);
    return item;
}

std::vector<StoreItem> StoreManager::getItems() {
    return storeItems;
}

int StoreManager::count() {
    return storeItems.size();
}
