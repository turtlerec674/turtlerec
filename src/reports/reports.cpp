#include "reports.h"

static std::vector<Report> reports;
static int nextReportId = 1;

Report ReportManager::createReport(int reporterId, int targetId, const std::string& reason) {
    Report report{nextReportId++, reporterId, targetId, reason, "open"};
    reports.push_back(report);
    return report;
}

bool ReportManager::closeReport(int reportId) {
    for (auto& r : reports) {
        if (r.id == reportId) {
            r.status = "closed";
            return true;
        }
    }
    return false;
}

int ReportManager::count() {
    return reports.size();
}
