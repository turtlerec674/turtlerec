#include "phase8.h"

std::string Phase8::avatar() {
    return "{\"equipped\":[\"hoodie\",\"watch\",\"hair\"]}";
}

std::string Phase8::recnetFeed() {
    return "{\"posts\":[{\"id\":1,\"author\":\"Tyler\",\"text\":\"Welcome to TurtleRec!\"}]}";
}

std::string Phase8::dorm() {
    return "{\"name\":\"Tyler's Dorm\",\"theme\":\"Classic\",\"visitors\":0}";
}

std::string Phase8::achievements() {
    return "{\"achievements\":[{\"id\":1,\"name\":\"Welcome\",\"unlocked\":true}]}";
}

std::string Phase8::leaderboards() {
    return "{\"leaderboards\":[{\"name\":\"Paintball\",\"score\":1000}]}";
}

std::string Phase8::messages() {
    return "{\"messages\":[{\"from\":\"System\",\"text\":\"Welcome!\"}]}";
}

std::string Phase8::invites() {
    return "{\"invites\":[]}";
}

std::string Phase8::presence() {
    return "{\"status\":\"Online\",\"room\":\"DormRoom\"}";
}

std::string Phase8::cloudsave() {
    return "{\"saves\":[]}";
}
