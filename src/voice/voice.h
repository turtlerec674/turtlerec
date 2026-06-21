#pragma once
#include <vector>

struct VoiceChannel {
    int roomId;
    std::vector<int> users;
};

class VoiceManager {
public:
    static VoiceChannel createChannel(int roomId);
    static bool joinVoice(int roomId, int userId);
    static bool leaveVoice(int roomId, int userId);
    static int count();
};
