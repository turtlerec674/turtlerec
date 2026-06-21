#pragma once
#include <vector>

struct RRPlusSub {
    int userId;
    bool active;
    int monthlyTokens;
};

class RRPlusManager {
public:
    static RRPlusSub activate(int userId);
    static int count();
};
