add_library(data SHARED
    src/data.cpp
    include/data.hpp
)

target_include_directories(data PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

find_package(SQLite3 REQUIRED)

target_link_libraries(data PUBLIC SQLite::SQLite3)

target_compile_definitions(data PRIVATE DATA_EXPORTS)