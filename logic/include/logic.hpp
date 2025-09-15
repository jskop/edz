#include <tuple>
#include <vector>
#ifdef _WIN32
#define LOGIC_API extern "C" __declspec(dllexport)
#else
#define LOGIC_API
#endif
#include <string>

namespace logic {
LOGIC_API std::string app_version();
LOGIC_API bool ensure_db_initialized(const std::string &path);
LOGIC_API bool add_student(const std::string& name, const std::string& surname);
LOGIC_API std::vector<std::tuple<int, std::string, std::string>> list_students();
LOGIC_API void ensure_db_closed();
} // namespace logic