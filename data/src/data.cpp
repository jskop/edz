#include "data.hpp"
#include <iostream>
#include <ostream>
#include <sqlite3.h>
#include <tuple>
#include <vector>

sqlite3 *db;
namespace data {

int init_db(const std::string &db_path) {
  // Implementation of database initialization
  int opened = sqlite3_open(db_path.c_str(), &db);
  if (opened) {
    std::cerr << "Database could not be opened: " << sqlite3_errmsg(db)
              << std::endl;
    return opened;
  }
  return 0; // Return 0 on success
}

void close_db() {
  if (db) {
    sqlite3_close(db);
    db = nullptr;
  }
}

bool executeSql(const std::string &sql) {
  if (!db) {
    std::cerr << "Database not initialized!" << std::endl;
    return false;
  }
  char *error;
  auto result = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &error);

  if (result) {
    std::cerr << "SQL error: " << error << std::endl;
    sqlite3_free(error);
    return false;
  }

  return true;
}

bool create_schema() {

  if (!executeSql("CREATE TABLE IF NOT EXISTS Students(Id INTEGER NOT NULL "
                  "PRIMARY KEY AUTOINCREMENT, Name TEXT, Surname TEXT)")) {
    return false;
  }
  if (!executeSql(
          "CREATE TABLE IF NOT EXISTS Grades(Id INTEGER NOT NULL PRIMARY KEY "
          "AUTOINCREMENT, Student_id INTEGER, Subject TEXT, Value INTEGER)")) {
    return false;
  }
  return true;
}

bool add_student(const std::string &name, const std::string &surname) {
  const char *sql = "INSERT INTO Students(Name, Surname) VALUES(?, ?);";
  sqlite3_stmt *stmt;

  auto result = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

  if (result) {
    std::cerr << "Prepare failed: " << sqlite3_errmsg(db) << std::endl;
    return false;
  }
  sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 2, surname.c_str(), -1, SQLITE_STATIC);

  result = sqlite3_step(stmt);
  sqlite3_finalize(stmt);

  if (result != SQLITE_DONE) {
    std::cerr << "Insert failed: " << sqlite3_errmsg(db) << std::endl;
    return false;
  }

  return true;
}

std::vector<std::tuple<int, std::string, std::string>> get_students() {
  sqlite3_stmt *stmt;
  auto result =
      sqlite3_prepare_v2(db, "SELECT * FROM Students", -1, &stmt, nullptr);

  std::vector<std::tuple<int, std::string, std::string>> students;

  if (result) {
    std::cerr << "Prepare failed: " << sqlite3_errmsg(db) << std::endl;
    return students;
  }

  while (sqlite3_step(stmt) == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0);
    std::string name(
        reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
    std::string surname(
        reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
    students.emplace_back(
        std::tuple<int, std::string, std::string>(id, name, surname));
  }
  sqlite3_finalize(stmt);
  return students;
}

} // namespace data