#include "cloudsave.h"
std::string CloudSaveManager::save() {
    return "{\"saved\":true,\"slot\":\"main\"}";
}
std::string CloudSaveManager::load() {
    return "{\"loaded\":true,\"data\":{\"level\":1,\"xp\":0,\"tokens\":1000}}";
}
