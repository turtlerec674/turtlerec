#pragma once
#include <string>
#include <vector>

struct Invite {
    int id;
    int fromUserId;
    int toUserId;
    int roomId;
    std::string status;
};

class InviteManager {
public:
    static Invite sendInvite(int fromUserId, int toUserId, int roomId);
    static bool acceptInvite(int inviteId);
    static int count();
};
