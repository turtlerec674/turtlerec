#include "gameplaypack.h"

std::string GameplayPack::circuits() {
    return "{\"chips\":450,\"connections\":1800,\"variables\":230,\"events\":520,\"status\":\"ready\"}";
}

std::string GameplayPack::inventions() {
    return "{\"inventions\":500,\"downloads\":1200,\"ratings\":300,\"comments\":90}";
}

std::string GameplayPack::makerpen() {
    return "{\"spawn\":true,\"delete\":true,\"move\":true,\"rotate\":true,\"scale\":true,\"clone\":true,\"undo\":true,\"redo\":true,\"grouping\":true}";
}

std::string GameplayPack::paintball() {
    return "{\"mode\":\"paintball\",\"kills\":0,\"deaths\":0,\"assists\":0,\"flagCaptures\":0,\"wins\":0,\"losses\":0,\"rank\":1}";
}

std::string GameplayPack::lasertag() {
    return "{\"mode\":\"laser_tag\",\"score\":0,\"teams\":true,\"powerups\":true,\"rank\":1}";
}

std::string GameplayPack::bowling() {
    return "{\"mode\":\"bowling\",\"frames\":10,\"highScore\":0}";
}

std::string GameplayPack::charades() {
    return "{\"mode\":\"charades\",\"rounds\":5,\"drawing\":true,\"guessing\":true}";
}

std::string GameplayPack::dodgeball() {
    return "{\"mode\":\"dodgeball\",\"teams\":2,\"rounds\":3,\"scoreLimit\":5}";
}

std::string GameplayPack::npcs() {
    return "{\"npcs\":[{\"id\":1,\"name\":\"Guide Bot\",\"roomId\":1,\"personality\":\"helpful\",\"voiceId\":\"guide_01\"}]}";
}

std::string GameplayPack::teleport() {
    return "{\"teleport\":true,\"player\":true,\"room\":true,\"instance\":true}";
}

std::string GameplayPack::seasons() {
    return "{\"battlePass\":true,\"season\":\"Alpha Season\",\"dailyStore\":true,\"challenges\":true,\"xpService\":true}";
}

std::string GameplayPack::developer() {
    return "{\"developerConsole\":true,\"metrics\":true,\"crashReporter\":true,\"patchNotes\":true,\"cdn\":true}";
}
