#include "phase7.h"

std::string Phase7::friends() {
    return "{\"friends\":[{\"id\":2,\"username\":\"Turtle\",\"status\":\"online\"}],\"requests\":[],\"blocked\":[]}";
}

std::string Phase7::parties() {
    return "{\"party\":{\"id\":1,\"leader\":1,\"members\":[1],\"privacy\":\"friends\"}}";
}

std::string Phase7::notifications() {
    return "{\"notifications\":[{\"id\":1,\"type\":\"SYSTEM\",\"message\":\"Welcome to TurtleRec\",\"read\":false}]}";
}

std::string Phase7::clubs() {
    return "{\"clubs\":[{\"id\":1,\"name\":\"TurtleRec Devs\",\"role\":\"Owner\",\"members\":1}]}";
}

std::string Phase7::inventory() {
    return "{\"inventory\":[{\"id\":101,\"name\":\"Starter Hoodie\",\"type\":\"cosmetic\",\"equipped\":true},{\"id\":201,\"name\":\"Starter MakerPen\",\"type\":\"tool\",\"equipped\":true}]}";
}

std::string Phase7::economy() {
    return "{\"wallet\":{\"tokens\":1000,\"tickets\":0},\"store\":[{\"id\":1,\"name\":\"Starter Hoodie\",\"price\":250}]}";
}

std::string Phase7::creatorEconomy() {
    return "{\"creator\":{\"earnings\":0,\"pendingPayout\":0,\"uploads\":0,\"status\":\"enabled\"}}";
}
