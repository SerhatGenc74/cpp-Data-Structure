cmake_minimum_required(VERSION 3.5)
project(DATASTRUCTURES CXX)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
# Add all source files in the src directory
file(GLOB_RECURSE SOURCE 
    src/*.h
    src/*.cpp
    )

add_executable(${PROJECT_NAME}  ${SOURCE}) 