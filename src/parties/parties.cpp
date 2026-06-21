#include "parties.h"
#include <algorithm>

static std::vector<Party> parties;
static int nextPartyId = 1;

Party PartyManager::createParty(int ownerId) {
    Party party{nextPartyId++, ownerId, {ownerId}};
    parties.push_back(party);
    return party;
}

bool PartyManager::joinParty(int partyId, int userId) {
    for (auto& p : parties) {
        if (p.id == partyId) {
            if (std::find(p.members.begin(), p.members.end(), userId) == p.members.end()) {
                p.members.push_back(userId);
            }

            return true;
        }
    }

    return false;
}

int PartyManager::count() {
    return parties.size();
}
