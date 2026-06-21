#include "friends.h"

static std::vector<FriendLink> friends;
static int nextFriendId = 1;

FriendLink FriendManager::sendRequest(int userId, int friendId) {
    FriendLink link{nextFriendId++, userId, friendId, "pending"};
    friends.push_back(link);
    return link;
}

bool FriendManager::acceptRequest(int requestId) {
    for (auto& f : friends) {
        if (f.id == requestId) {
            f.status = "accepted";
            return true;
        }
    }
    return false;
}

std::vector<FriendLink> FriendManager::getFriends(int userId) {
    std::vector<FriendLink> result;

    for (auto& f : friends) {
        if ((f.userId == userId || f.friendId == userId) && f.status == "accepted") {
            result.push_back(f);
        }
    }

    return result;
}

int FriendManager::count() {
    return friends.size();
}
