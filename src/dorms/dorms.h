#pragma once
#include <string>
#include <vector>

struct Dorm {
    int ownerId;
    std::string name;
    std::vector<int> decorations;
};

class DormManager {
public:
    static Dorm createDorm(int ownerId, const std::string& name);
    static Dorm* getDorm(int ownerId);
    static bool addDecoration(int ownerId, int itemId);
    static int count();
};
