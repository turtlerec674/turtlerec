#pragma once
#include <string>
#include <vector>

struct Session {
    int id;
    int userId;
    std::string token;
    long expiresAt;
};

class SessionManager {
public:
    static Session createSession(int userId);
    static Session* getSession(const std::string& token);
    static int count();
};
