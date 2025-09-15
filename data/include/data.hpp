#include <tuple>
#include <vector>
#ifdef _WIN32
#define DATA_API extern "C" __declspec(dllexport)
#else
#define DATA_API
#endif

#include <string>

namespace data {
DATA_API int init_db(const std::string &db_path);
DATA_API void close_db();
DATA_API bool create_schema();
DATA_API bool add_student(const std::string &name, const std::string &surname);
DATA_API std::vector<std::tuple<int, std::string, std::string>> get_students();
} // namespace data
