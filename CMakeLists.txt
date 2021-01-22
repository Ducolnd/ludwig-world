cmake_minimum_required(VERSION 3.16)

project(ludwig_world)
include_directories("src/entities/" "src/world/")
file(GLOB SOURCES "src/entities/*.cpp" "src/world/*.cpp")

set(CMAKE_CXX_STANDARD 17)


add_executable(ludwig_world ${SOURCES})