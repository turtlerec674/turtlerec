#include "announcements.h"

std::string AnnouncementManager::list() {
    return "{\"announcements\":[{\"id\":1,\"title\":\"Server Online\",\"message\":\"Welcome to RRServer.\"}]}";
}

std::string AnnouncementManager::create() {
    return "{\"created\":true,\"announcementId\":2}";
}
