#pragma once
#include <vector>

struct Party {
    int id;
    int ownerId;
    std::vector<int> members;
};

class PartyManager {
public:
    static Party createParty(int ownerId);
    static bool joinParty(int partyId, int userId);
    static int count();
};
