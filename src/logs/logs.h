#pragma once
#include <string>
#include <vector>

struct LogEntry {
    int id;
    std::string message;
};

class LogManager {
public:
    static LogEntry log(const std::string& message);
    static int count();
};
