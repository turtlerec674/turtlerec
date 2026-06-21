#pragma once
#include <string>
#include <vector>

struct Report {
    int id;
    int reporterId;
    int targetId;
    std::string reason;
    std::string status;
};

class ReportManager {
public:
    static Report createReport(int reporterId, int targetId, const std::string& reason);
    static bool closeReport(int reportId);
    static int count();
};
