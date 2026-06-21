#include "equipment.h"
std::string EquipmentManager::get() {
    return "{\"equipment\":{\"shirt\":101,\"hat\":0,\"hair\":0,\"gloves\":0}}";
}
std::string EquipmentManager::equip() {
    return "{\"equipped\":true,\"slot\":\"shirt\",\"itemId\":101}";
}
