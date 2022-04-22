cmake_minimum_required(VERSION 3.10)

project(calc VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(calc ${SOURCES})
target_include_directories(calc PUBLIC src/)