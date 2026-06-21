#pragma once
#include <string>

class RecNetManager {
public:
    static std::string feed();
    static std::string profile();
    static std::string post();
    static std::string like();
    static std::string comment();
};
