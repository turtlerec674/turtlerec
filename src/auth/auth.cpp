#include "auth.h"
#include <vector>
#include <string>
#include <ctime>

static std::vector<std::string> tokens;

std::string AuthManager::registerUser(const std::string& username) {
    return "{\"registered\":true,\"username\":\"" + username + "\"}";
}

std::string AuthManager::loginUser(int userId) {
    std::string token = "token_" + std::to_string(userId) + "_" + std::to_string(std::time(nullptr));
    tokens.push_back(token);
    return token;
}

int AuthManager::count() {
    return tokens.size();
}
