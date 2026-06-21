#pragma once
#include <string>

class AuthManager {
public:
    static std::string registerUser(const std::string& username);
    static std::string loginUser(int userId);
    static int count();
};
