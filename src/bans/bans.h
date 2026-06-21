#pragma once
#include <string>
#include <vector>

struct Ban {
    int id;
    int userId;
    std::string reason;
    bool active;
};

class BanManager {
public:
    static Ban banUser(int userId, const std::string& reason);
    static bool isBanned(int userId);
    static int count();
};
