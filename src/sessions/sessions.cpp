#include "sessions.h"
#include <ctime>

static std::vector<Session> sessions;
static int nextSessionId = 1;

Session SessionManager::createSession(int userId) {
    Session session{
        nextSessionId++,
        userId,
        "session_" + std::to_string(std::time(nullptr)) + "_" + std::to_string(userId),
        std::time(nullptr) + 86400
    };

    sessions.push_back(session);
    return session;
}

Session* SessionManager::getSession(const std::string& token) {
    for (auto& s : sessions) {
        if (s.token == token) return &s;
    }

    return nullptr;
}

int SessionManager::count() {
    return sessions.size();
}
