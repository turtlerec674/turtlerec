#include "consumables.h"

static std::vector<Consumable> consumables;
static int nextConsumableId = 1;

Consumable ConsumableManager::addConsumable(int userId, const std::string& name, int quantity) {
    Consumable consumable{nextConsumableId++, userId, name, quantity};
    consumables.push_back(consumable);
    return consumable;
}

int ConsumableManager::count() {
    return consumables.size();
}
