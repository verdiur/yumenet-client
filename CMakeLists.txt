cmake_minimum_required(VERSION 3.10)
project(yumenet)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

add_subdirectory(libs/raylib)
add_subdirectory(libs/entt)

add_executable(${PROJECT_NAME}
    # main
    src/main.cpp

    # components
    src/comp/position.hpp
    src/comp/render.hpp
    src/comp/rotation.hpp
    src/comp/scale.hpp
    src/comp/tile.hpp

    # systems
    src/sys/render.hpp

    # core
    src/core/app.hpp
    src/core/app.cpp
    src/core/game.hpp
    src/core/game.cpp

    # utils
)

target_include_directories(${PROJECT_NAME}
    PUBLIC src/
)

target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} EnTT::EnTT)
