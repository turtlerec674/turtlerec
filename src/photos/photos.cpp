#include "photos.h"

static std::vector<Photo> photos;
static int nextPhotoId = 1;

Photo PhotoManager::savePhoto(int userId, int roomId, const std::string& url) {
    Photo photo{nextPhotoId++, userId, roomId, url};
    photos.push_back(photo);
    return photo;
}

int PhotoManager::count() {
    return photos.size();
}
