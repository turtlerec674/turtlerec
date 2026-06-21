#include "realapi.h"

std::string RealAPI::authRegister() {
    return "{\"success\":true,\"userId\":1,\"username\":\"test_user\",\"token\":\"dev_session_token\"}";
}

std::string RealAPI::authLogin() {
    return "{\"success\":true,\"userId\":1,\"username\":\"test_user\",\"displayName\":\"Roxy\",\"token\":\"dev_session_token\"}";
}

std::string RealAPI::roomsList() {
    return "{\"rooms\":[{\"id\":1,\"name\":\"Dorm Room\",\"players\":1,\"maxPlayers\":20},{\"id\":2,\"name\":\"Rec Center\",\"players\":5,\"maxPlayers\":40}]}";
}

std::string RealAPI::roomsJoin() {
    return "{\"joined\":true,\"roomId\":2,\"instanceId\":3,\"joinToken\":\"instance_join_token\",\"server\":\"127.0.0.1\",\"port\":3000}";
}

std::string RealAPI::inventoryGet() {
    return "{\"items\":[{\"id\":101,\"name\":\"Starter Shirt\",\"type\":\"shirt\",\"equipped\":true},{\"id\":201,\"name\":\"Dorm Chair\",\"type\":\"dorm_item\",\"equipped\":false}]}";
}

std::string RealAPI::recnetFeed() {
    return "{\"posts\":[{\"id\":1,\"userId\":1,\"username\":\"test_user\",\"text\":\"Welcome to TurtleRec\",\"likes\":0,\"comments\":0}]}";
}

std::string RealAPI::photosUpload() {
    return "{\"uploaded\":true,\"photoId\":1,\"url\":\"/assets/photos/photo_001.png\",\"ownerId\":1}";
}

std::string RealAPI::clientCompat() {
    return "{\"compatibility\":\"2022-client\",\"apiVersion\":\"v1\",\"backend\":\"RRServer\",\"status\":\"ready\"}";
}

std::string RealAPI::photonJoin() {
    return "{\"photonCompatible\":true,\"appId\":\"turtlerec-dev\",\"region\":\"local\",\"roomName\":\"instance_3\",\"userId\":1}";
}

std::string RealAPI::assetServe() {
    return "{\"assets\":[{\"id\":1,\"type\":\"image\",\"url\":\"/assets/images/default.png\"},{\"id\":2,\"type\":\"bundle\",\"url\":\"/assets/bundles/base\"}]}";
}

std::string RealAPI::adminPanel() {
    return "{\"admin\":true,\"users\":1,\"rooms\":2,\"reports\":1,\"bans\":1,\"instances\":3}";
}
