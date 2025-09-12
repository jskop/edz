cmake_minimum_required(VERSION 3.21)
project(e-dziennik LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    set(SQLite3_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rd_party)
    set(SQLite3_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/sqlite3.dll)
endif()

add_subdirectory(data)
add_subdirectory(logic)
add_subdirectory(ui)