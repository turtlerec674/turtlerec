#pragma once
#include <string>
#include <vector>

struct Consumable {
    int id;
    int userId;
    std::string name;
    int quantity;
};

class ConsumableManager {
public:
    static Consumable addConsumable(int userId, const std::string& name, int quantity);
    static int count();
};
