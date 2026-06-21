#include "screenshots.h"

static std::vector<Screenshot> screenshots;
static int nextScreenshotId = 1;

Screenshot ScreenshotManager::saveScreenshot(int userId, const std::string& path) {
    Screenshot screenshot{nextScreenshotId++, userId, path};
    screenshots.push_back(screenshot);
    return screenshot;
}

int ScreenshotManager::count() {
    return screenshots.size();
}
