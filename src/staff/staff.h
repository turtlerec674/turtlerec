#pragma once
#include <string>

class StaffManager {
public:
    static std::string ranks();
    static std::string getTag();
    static std::string toggleTag();
    static std::string promote();
    static std::string demote();
};
