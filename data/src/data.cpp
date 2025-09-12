#include "data.hpp"
#include <cstdio>
#include <sqlite3.h>

sqlite3* db;

int init_db(const std::string& db_path) {
    // Implementation of database initialization
    int opened = sqlite3_open(db_path.c_str(), &db);
    if (opened) {
        printf("Database could not be opened %s\n", sqlite3_errmsg(db));
    }
    return 0; // Return 0 on success
}

void close_db() {
    sqlite3_close(db);
}