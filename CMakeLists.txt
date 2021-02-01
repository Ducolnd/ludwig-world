cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_COMPILER "gcc-10")
set(CMAKE_CXX_COMPILER "/usr/bin/g++-10")


project(ludwig_world)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_BUILD_TYPE Debug) # For debug

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

file(GLOB_RECURSE sources "src/*.cpp")
add_executable(ludwig_world ${sources})

target_link_libraries(ludwig_world sfml-graphics sfml-window sfml-system)

target_include_directories(ludwig_world PRIVATE "../entt/src")
target_include_directories(ludwig_world PRIVATE "src/")

