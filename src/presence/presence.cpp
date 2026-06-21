#include "presence.h"

static std::vector<Presence> presences;

Presence PresenceManager::setPresence(int userId, const std::string& status) {
    for (auto& p : presences) {
        if (p.userId == userId) {
            p.status = status;
            return p;
        }
    }

    Presence presence{userId, status};
    presences.push_back(presence);
    return presence;
}

Presence* PresenceManager::getPresence(int userId) {
    for (auto& p : presences) {
        if (p.userId == userId) return &p;
    }

    return nullptr;
}

int PresenceManager::count() {
    return presences.size();
}
