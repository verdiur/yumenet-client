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
    src/comp/direction.hpp
    src/comp/move.hpp
    src/comp/origin.hpp
    src/comp/position.hpp
    src/comp/render.hpp
    src/comp/rotation.hpp
    src/comp/scale.hpp
    src/comp/types.hpp

    # systems
    src/sys/move.hpp
    src/sys/move.cpp
    src/sys/render.hpp
    src/sys/render.cpp

    # core
    src/core/consts.hpp
    src/core/app.hpp
    src/core/app.cpp
    src/core/game.hpp
    src/core/game.cpp
    src/core/world.hpp
    src/core/world.cpp

    # utils
    src/utils/rng.hpp
    src/utils/dir_to_pos.hpp
    src/utils/dir_to_pos.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC src/
)

target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} EnTT::EnTT)
