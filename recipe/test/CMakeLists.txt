cmake_minimum_required(VERSION 3.12)

project(loguru_example LANGUAGES CXX)

find_package(Threads REQUIRED)
find_package(loguru REQUIRED CONFIG)

file(GLOB sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(loguru-example ${sources})
target_link_libraries(loguru-example PRIVATE loguru::loguru Threads::Threads)
