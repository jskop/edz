#ifdef _WIN32
#define DATA_API extern "C" __declspec(dllexport)
#else
#define DATA_API
#endif

#include <string>

DATA_API int init_db(const std::string &db_path);
DATA_API void close_db();