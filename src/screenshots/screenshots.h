#pragma once
#include <string>
#include <vector>

struct Screenshot {
    int id;
    int userId;
    std::string path;
};

class ScreenshotManager {
public:
    static Screenshot saveScreenshot(int userId, const std::string& path);
    static int count();
};
