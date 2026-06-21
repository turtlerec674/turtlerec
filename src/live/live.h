#pragma once
#include <string>

class LiveManager {
public:
    static std::string heartbeat();
    static std::string richPresence();
    static std::string roomEvent();
};
