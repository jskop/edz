add_library(logic SHARED
    src/logic.cpp
    include/logic.hpp
)


target_include_directories(logic PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(logic PUBLIC data)

target_compile_definitions(logic PRIVATE LOGIC_EXPORTS)