#include "quests.h"
std::string QuestManager::daily() {
    return "{\"daily\":[{\"id\":1,\"name\":\"Play one room\",\"reward\":100,\"complete\":false}]}";
}
std::string QuestManager::weekly() {
    return "{\"weekly\":[{\"id\":1,\"name\":\"Earn 1000 XP\",\"reward\":500,\"complete\":false}]}";
}
std::string QuestManager::complete() {
    return "{\"completed\":true,\"reward\":100}";
}
