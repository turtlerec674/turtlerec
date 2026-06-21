#pragma once
#include <string>
#include <vector>

struct Message {
    int id;
    int fromUserId;
    int toUserId;
    std::string content;
};

class MessageManager {
public:
    static Message sendMessage(int fromUserId, int toUserId, const std::string& content);
    static std::vector<Message> getMessages(int userId);
    static int count();
};
