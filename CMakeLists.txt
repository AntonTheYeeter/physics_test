cmake_minimum_required(VERSION 3.27.0)

project(physics)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

file(GLOB SOURCES src/*.c tools/*.c)

add_executable(physics ${SOURCES})

target_link_libraries(physics PUBLIC SDL2)
target_include_directories(physics PUBLIC ${CMAKE_SOURCE_DIR}/tools)