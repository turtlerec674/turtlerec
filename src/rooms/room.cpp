#include "room.h"

static std::vector<Room> rooms;
static int nextRoomId = 1;

Room RoomManager::createRoom(const std::string& name, int maxPlayers) {
    Room room{nextRoomId++, name, maxPlayers};
    rooms.push_back(room);
    return room;
}

int RoomManager::count() {
    return rooms.size();
}

std::vector<Room> RoomManager::getRooms() {
    return rooms;
}
