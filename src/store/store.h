#pragma once
#include <string>
#include <vector>

struct StoreItem {
    int id;
    std::string name;
    int price;
    std::string category;
};

class StoreManager {
public:
    static StoreItem addStoreItem(const std::string& name, int price, const std::string& category);
    static std::vector<StoreItem> getItems();
    static int count();
};
