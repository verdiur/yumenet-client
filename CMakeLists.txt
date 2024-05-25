cmake_minimum_required(VERSION 3.10)
project(yumenet)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

add_subdirectory(libs/raylib)
add_subdirectory(libs/entt)

add_executable(${PROJECT_NAME}
    # main
    src/main.cc
    # components
    # core
    src/core/app.cc
    src/core/game.cc
    src/core/world.cc
    # systems
    src/sys/create.cc
    src/sys/update.cc
    src/sys/render.cc
    # utils
    src/utils/dir_to_pos.cc
)

target_include_directories(${PROJECT_NAME} PUBLIC
    src/
    libs/
)

target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} EnTT::EnTT)
