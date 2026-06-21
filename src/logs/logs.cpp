#include "logs.h"
#include <iostream>

static std::vector<LogEntry> logs;
static int nextLogId = 1;

LogEntry LogManager::log(const std::string& message) {
    LogEntry entry{nextLogId++, message};
    logs.push_back(entry);
    std::cout << "[LOG] " << message << std::endl;
    return entry;
}

int LogManager::count() {
    return logs.size();
}
