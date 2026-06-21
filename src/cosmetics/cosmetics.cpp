#include "cosmetics.h"

std::string CosmeticsManager::list() {
    return "{\"cosmetics\":[{\"id\":101,\"type\":\"shirt\",\"name\":\"Starter Shirt\"},{\"id\":102,\"type\":\"hat\",\"name\":\"Developer Cap\"},{\"id\":103,\"type\":\"badge\",\"name\":\"Staff Badge\"}]}";
}

std::string CosmeticsManager::equip() {
    return "{\"equipped\":true,\"cosmeticId\":102,\"slot\":\"hat\"}";
}
