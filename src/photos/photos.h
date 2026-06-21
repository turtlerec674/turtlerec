#pragma once
#include <string>
#include <vector>

struct Photo {
    int id;
    int userId;
    int roomId;
    std::string url;
};

class PhotoManager {
public:
    static Photo savePhoto(int userId, int roomId, const std::string& url);
    static int count();
};
