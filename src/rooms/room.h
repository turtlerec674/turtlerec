#pragma once
#include <string>
#include <vector>

struct Room {
    int id;
    std::string name;
    int maxPlayers;
};

class RoomManager {
public:
    static Room createRoom(const std::string& name, int maxPlayers);
    static int count();
    static std::vector<Room> getRooms();
};
