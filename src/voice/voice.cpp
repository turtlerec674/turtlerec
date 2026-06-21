#include "voice.h"
#include <algorithm>

static std::vector<VoiceChannel> channels;

VoiceChannel VoiceManager::createChannel(int roomId) {
    VoiceChannel channel{roomId, {}};
    channels.push_back(channel);
    return channel;
}

bool VoiceManager::joinVoice(int roomId, int userId) {
    for (auto& c : channels) {
        if (c.roomId == roomId) {
            if (std::find(c.users.begin(), c.users.end(), userId) == c.users.end()) {
                c.users.push_back(userId);
            }

            return true;
        }
    }

    createChannel(roomId);
    return joinVoice(roomId, userId);
}

bool VoiceManager::leaveVoice(int roomId, int userId) {
    for (auto& c : channels) {
        if (c.roomId == roomId) {
            c.users.erase(std::remove(c.users.begin(), c.users.end(), userId), c.users.end());
            return true;
        }
    }

    return false;
}

int VoiceManager::count() {
    return channels.size();
}
