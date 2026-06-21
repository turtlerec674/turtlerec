#include "dorms.h"

static std::vector<Dorm> dorms;

Dorm DormManager::createDorm(int ownerId, const std::string& name) {
    Dorm dorm{ownerId, name, {}};
    dorms.push_back(dorm);
    return dorm;
}

Dorm* DormManager::getDorm(int ownerId) {
    for (auto& d : dorms) {
        if (d.ownerId == ownerId) return &d;
    }

    return nullptr;
}

bool DormManager::addDecoration(int ownerId, int itemId) {
    Dorm* dorm = getDorm(ownerId);
    if (!dorm) return false;

    dorm->decorations.push_back(itemId);
    return true;
}

int DormManager::count() {
    return dorms.size();
}
