#include "rrplus.h"

static std::vector<RRPlusSub> subs;

RRPlusSub RRPlusManager::activate(int userId) {
    RRPlusSub sub{userId, true, 6000};
    subs.push_back(sub);
    return sub;
}

int RRPlusManager::count() {
    return subs.size();
}
