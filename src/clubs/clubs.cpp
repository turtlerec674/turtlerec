#include "clubs.h"
#include <algorithm>

static std::vector<Club> clubs;
static int nextClubId = 1;

Club ClubManager::createClub(int ownerId, const std::string& name) {
    Club club{nextClubId++, ownerId, name, {ownerId}};
    clubs.push_back(club);
    return club;
}

bool ClubManager::joinClub(int clubId, int userId) {
    for (auto& c : clubs) {
        if (c.id == clubId) {
            if (std::find(c.members.begin(), c.members.end(), userId) == c.members.end()) {
                c.members.push_back(userId);
            }
            return true;
        }
    }
    return false;
}

int ClubManager::count() {
    return clubs.size();
}
