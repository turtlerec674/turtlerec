#pragma once
#include <string>
#include <vector>

struct Club {
    int id;
    int ownerId;
    std::string name;
    std::vector<int> members;
};

class ClubManager {
public:
    static Club createClub(int ownerId, const std::string& name);
    static bool joinClub(int clubId, int userId);
    static int count();
};
