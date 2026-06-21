#pragma once
#include <string>

class SecurityManager {
public:
    static std::string audit();
    static std::string rateLimit();
    static std::string integrity();
};
