#include "logic.hpp"
#include <data.hpp>
#include <tuple>

namespace logic {

std::string app_version() { return "0.1"; }

bool ensure_db_initialized(const std::string &path) {
  if (data::init_db(path)) {
    return false;
  }
  return data::create_schema();
}

// call this on quit
void ensure_db_closed() {
    data::close_db();
}

bool add_student(const std::string &name, const std::string &surname) {
    return data::add_student(name, surname);
}

std::vector<std::tuple<int, std::string, std::string>> list_students() {
    return data::get_students();
}

} // namespace logic