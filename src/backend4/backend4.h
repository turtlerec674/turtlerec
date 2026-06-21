#pragma once
#include <string>

class Backend4 {
public:
    static std::string status();
    static std::string health();
    static std::string apiMap();
    static std::string production();
    static std::string realtime();
    static std::string persistence();
    static std::string deployment();
    static std::string diagnostics();
};
