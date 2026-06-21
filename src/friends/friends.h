#pragma once
#include <string>
#include <vector>

struct FriendLink {
    int id;
    int userId;
    int friendId;
    std::string status;
};

class FriendManager {
public:
    static FriendLink sendRequest(int userId, int friendId);
    static bool acceptRequest(int requestId);
    static std::vector<FriendLink> getFriends(int userId);
    static int count();
};
