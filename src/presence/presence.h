#pragma once
#include <string>
#include <vector>

struct Presence {
    int userId;
    std::string status;
};

class PresenceManager {
public:
    static Presence setPresence(int userId, const std::string& status);
    static Presence* getPresence(int userId);
    static int count();
};
