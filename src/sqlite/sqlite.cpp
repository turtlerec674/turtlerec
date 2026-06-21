#include "sqlite.h"
#include <iostream>
#include <sqlite3.h>

static sqlite3* db = nullptr;

bool SQLiteDB::open() {
    if (sqlite3_open("rrserver.db", &db) != SQLITE_OK) {
        std::cout << "Failed to open SQLite database." << std::endl;
        return false;
    }

    std::cout << "SQLite database opened." << std::endl;
    return true;
}

void SQLiteDB::init() {
    const char* sql =
        "CREATE TABLE IF NOT EXISTS accounts(id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT, email TEXT, displayName TEXT, level INTEGER);"
        "CREATE TABLE IF NOT EXISTS profiles(id INTEGER PRIMARY KEY AUTOINCREMENT, userId INTEGER, bio TEXT, xp INTEGER, level INTEGER);"
        "CREATE TABLE IF NOT EXISTS wallets(id INTEGER PRIMARY KEY AUTOINCREMENT, userId INTEGER, tokens INTEGER, credits INTEGER);"
        "CREATE TABLE IF NOT EXISTS rooms(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, maxPlayers INTEGER, currentPlayers INTEGER);"
        "CREATE TABLE IF NOT EXISTS friends(id INTEGER PRIMARY KEY AUTOINCREMENT, userId INTEGER, friendId INTEGER, status TEXT);"
        "CREATE TABLE IF NOT EXISTS messages(id INTEGER PRIMARY KEY AUTOINCREMENT, fromUserId INTEGER, toUserId INTEGER, content TEXT);"
        "CREATE TABLE IF NOT EXISTS inventory(id INTEGER PRIMARY KEY AUTOINCREMENT, userId INTEGER, itemName TEXT, equipped INTEGER);"
        "CREATE TABLE IF NOT EXISTS reports(id INTEGER PRIMARY KEY AUTOINCREMENT, reporterId INTEGER, targetId INTEGER, reason TEXT, status TEXT);"
        "CREATE TABLE IF NOT EXISTS bans(id INTEGER PRIMARY KEY AUTOINCREMENT, userId INTEGER, reason TEXT, active INTEGER);"
        "CREATE TABLE IF NOT EXISTS clubs(id INTEGER PRIMARY KEY AUTOINCREMENT, ownerId INTEGER, name TEXT);"
        "CREATE TABLE IF NOT EXISTS store(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, price INTEGER, category TEXT);"
        "CREATE TABLE IF NOT EXISTS photos(id INTEGER PRIMARY KEY AUTOINCREMENT, userId INTEGER, roomId INTEGER, url TEXT);"
        "CREATE TABLE IF NOT EXISTS gifts(id INTEGER PRIMARY KEY AUTOINCREMENT, fromUserId INTEGER, toUserId INTEGER, itemId INTEGER, claimed INTEGER);"
        "CREATE TABLE IF NOT EXISTS sessions(id INTEGER PRIMARY KEY AUTOINCREMENT, userId INTEGER, token TEXT, expiresAt INTEGER);"
        "CREATE TABLE IF NOT EXISTS logs(id INTEGER PRIMARY KEY AUTOINCREMENT, message TEXT);";

    char* error = nullptr;
    sqlite3_exec(db, sql, nullptr, nullptr, &error);

    if (error) {
        std::cout << "SQLite init error: " << error << std::endl;
        sqlite3_free(error);
    } else {
        std::cout << "SQLite tables ready." << std::endl;
    }
}

int SQLiteDB::count(const std::string& table) {
    if (!db) return 0;

    std::string sql = "SELECT COUNT(*) FROM " + table + ";";
    sqlite3_stmt* stmt = nullptr;
    int total = 0;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            total = sqlite3_column_int(stmt, 0);
        }
    }

    sqlite3_finalize(stmt);
    return total;
}

void SQLiteDB::seed() {
    if (count("accounts") > 0) {
        std::cout << "SQLite seed skipped." << std::endl;
        return;
    }

    const char* sql =
        "INSERT INTO accounts(username,email,displayName,level) VALUES('test_user','test@example.com','Roxy',1);"
        "INSERT INTO profiles(userId,bio,xp,level) VALUES(1,'Starter profile',0,1);"
        "INSERT INTO wallets(userId,tokens,credits) VALUES(1,1000,0);"
        "INSERT INTO rooms(name,maxPlayers,currentPlayers) VALUES('Dorm Room',20,1);"
        "INSERT INTO rooms(name,maxPlayers,currentPlayers) VALUES('Rec Center',40,5);"
        "INSERT INTO friends(userId,friendId,status) VALUES(1,2,'pending');"
        "INSERT INTO messages(fromUserId,toUserId,content) VALUES(1,2,'Hello from SQLite.');"
        "INSERT INTO inventory(userId,itemName,equipped) VALUES(1,'Starter Shirt',1);"
        "INSERT INTO reports(reporterId,targetId,reason,status) VALUES(1,99,'Seed report','open');"
        "INSERT INTO bans(userId,reason,active) VALUES(99,'Seed ban',1);"
        "INSERT INTO clubs(ownerId,name) VALUES(1,'Starter Club');"
        "INSERT INTO store(name,price,category) VALUES('Starter Hoodie',250,'clothing');"
        "INSERT INTO photos(userId,roomId,url) VALUES(1,1,'photo_001.png');"
        "INSERT INTO gifts(fromUserId,toUserId,itemId,claimed) VALUES(1,2,101,0);"
        "INSERT INTO sessions(userId,token,expiresAt) VALUES(1,'seed_session',999999999);"
        "INSERT INTO logs(message) VALUES('Seed data created');";

    char* error = nullptr;
    sqlite3_exec(db, sql, nullptr, nullptr, &error);

    if (error) {
        std::cout << "SQLite seed error: " << error << std::endl;
        sqlite3_free(error);
    } else {
        std::cout << "SQLite seed data inserted." << std::endl;
    }
}

void SQLiteDB::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
        std::cout << "SQLite database closed." << std::endl;
    }
}
