add_executable(ui
    src/main.cpp
)

target_include_directories(ui PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set(Qt6_DIR "C:/Qt/6.9.2/msvc2022_64/lib/cmake/Qt6")

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)

target_link_libraries(ui PRIVATE logic data Qt6::Widgets Qt6::Core Qt6::Gui)
