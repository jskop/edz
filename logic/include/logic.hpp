#ifdef _WIN32
#define LOGIC_API extern "C" __declspec(dllexport)
#else
#define LOGIC_API
#endif
#include <string>

LOGIC_API std::string app_version();