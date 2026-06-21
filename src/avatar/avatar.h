#pragma once
#include <string>
#include <vector>

struct Avatar {
    int userId;
    int shirt;
    int hat;
    int gloves;
    int hair;
};

class AvatarManager {
public:
    static Avatar createAvatar(int userId);
    static Avatar* getAvatar(int userId);
    static bool equipItem(int userId, const std::string& slot, int itemId);
    static int count();
};
