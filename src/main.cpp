#include "server/server.h"
#include "http/httpserver.h"
#include "sqlite/sqlite.h"

int main() {
    SQLiteDB::open();
    SQLiteDB::init();
    SQLiteDB::seed();

    Server server;

    server.boot();
    server.loadTestData();
    server.printStatus();

    HttpServer::start(3000);

    SQLiteDB::close();

    return 0;
}
