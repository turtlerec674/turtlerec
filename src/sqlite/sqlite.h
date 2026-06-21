#pragma once
#include <string>

class SQLiteDB {
public:
    static bool open();
    static void init();
    static void seed();
    static int count(const std::string& table);
    static void close();
};
