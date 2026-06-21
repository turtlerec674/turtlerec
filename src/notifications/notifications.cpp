#include "notifications.h"

static std::vector<Notification> notifications;
static int nextNotificationId = 1;

Notification NotificationManager::sendNotification(int userId, const std::string& title, const std::string& message) {
    Notification notification{nextNotificationId++, userId, title, message, false};
    notifications.push_back(notification);
    return notification;
}

bool NotificationManager::markRead(int notificationId) {
    for (auto& n : notifications) {
        if (n.id == notificationId) {
            n.read = true;
            return true;
        }
    }

    return false;
}

std::vector<Notification> NotificationManager::getNotifications(int userId) {
    std::vector<Notification> result;

    for (auto& n : notifications) {
        if (n.userId == userId) {
            result.push_back(n);
        }
    }

    return result;
}

int NotificationManager::count() {
    return notifications.size();
}
