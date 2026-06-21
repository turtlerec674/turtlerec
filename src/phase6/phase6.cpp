#include "phase6.h"

std::string Phase6::websocket() {
    return "{\"websocket\":true,\"port\":3001,\"events\":[\"presence\",\"party\",\"room\",\"notification\",\"voice\"]}";
}

std::string Phase6::photoUpload() {
    return "{\"uploaded\":true,\"photoId\":1,\"ownerId\":1,\"url\":\"/assets/photos/photo_001.png\"}";
}

std::string Phase6::assets() {
    return "{\"assetManager\":true,\"bundles\":true,\"images\":true,\"thumbnails\":true,\"basePath\":\"/assets\"}";
}

std::string Phase6::movementAuthority() {
    return "{\"movementAuthority\":true,\"objectSync\":true,\"dormSync\":true,\"circuitSync\":true}";
}

std::string Phase6::dashboard() {
    return "{\"dashboard\":true,\"users\":1,\"reports\":1,\"rooms\":2,\"bans\":1,\"instances\":3}";
}

std::string Phase6::clientSupport() {
    return "{\"auth\":\"/auth/login\",\"register\":\"/auth/register\",\"me\":\"/players/me\",\"rooms\":\"/rooms\",\"join\":\"/rooms/join\",\"inventory\":\"/inventory\",\"store\":\"/store\",\"friends\":\"/friends\",\"notifications\":\"/notifications\",\"recnet\":\"/recnet/feed\"}";
}
