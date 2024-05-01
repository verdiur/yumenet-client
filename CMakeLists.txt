cmake_minimum_required(VERSION 3.10)
project(yumenet)

add_subdirectory(libs/raylib)
add_subdirectory(libs/entt)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_include_directories(${PROJECT_NAME}
    
)

target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} EnTT::EnTT)
