#include "invites.h"

static std::vector<Invite> invites;
static int nextInviteId = 1;

Invite InviteManager::sendInvite(int fromUserId, int toUserId, int roomId) {
    Invite invite{nextInviteId++, fromUserId, toUserId, roomId, "pending"};
    invites.push_back(invite);
    return invite;
}

bool InviteManager::acceptInvite(int inviteId) {
    for (auto& i : invites) {
        if (i.id == inviteId) {
            i.status = "accepted";
            return true;
        }
    }

    return false;
}

int InviteManager::count() {
    return invites.size();
}
