#include "logic.hpp"
#include <data.hpp>

std::string app_version() {
    return "0.1";
}

bool ensure_db_initialized(const std::string &path) {
    if (init_db(path)) {
        return false;
    }
    return true;
}