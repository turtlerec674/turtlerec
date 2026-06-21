#include "messages.h"

static std::vector<Message> messages;
static int nextMessageId = 1;

Message MessageManager::sendMessage(int fromUserId, int toUserId, const std::string& content) {
    Message message{nextMessageId++, fromUserId, toUserId, content};
    messages.push_back(message);
    return message;
}

std::vector<Message> MessageManager::getMessages(int userId) {
    std::vector<Message> result;

    for (auto& m : messages) {
        if (m.fromUserId == userId || m.toUserId == userId) {
            result.push_back(m);
        }
    }

    return result;
}

int MessageManager::count() {
    return messages.size();
}
