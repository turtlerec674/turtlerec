#pragma once
#include <string>
#include <vector>

struct Notification {
    int id;
    int userId;
    std::string title;
    std::string message;
    bool read;
};

class NotificationManager {
public:
    static Notification sendNotification(int userId, const std::string& title, const std::string& message);
    static bool markRead(int notificationId);
    static std::vector<Notification> getNotifications(int userId);
    static int count();
};
