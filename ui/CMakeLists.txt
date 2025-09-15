set(CMAKE_AUTOMOC ON)

add_executable(ui
    src/main.cpp
    src/MainWindow.h
    src/MainWindow.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)

qt_standard_project_setup()

target_include_directories(ui PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (WIN32 AND NOT DEFINED Qt6_DIR)
    set(Qt6_DIR "C:/Qt/6.9.2/msvc2022_64/lib/cmake/Qt6")
endif()

target_link_libraries(ui PRIVATE logic data Qt6::Widgets Qt6::Core Qt6::Gui)
