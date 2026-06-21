#pragma once
#include <string>

class RealAPI {
public:
    static std::string authRegister();
    static std::string authLogin();
    static std::string roomsList();
    static std::string roomsJoin();
    static std::string inventoryGet();
    static std::string recnetFeed();
    static std::string photosUpload();
    static std::string clientCompat();
    static std::string photonJoin();
    static std::string assetServe();
    static std::string adminPanel();
};
