cmake_minimum_required(VERSION 3.16)
project(2048)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML REQUIRED COMPONENTS Graphics Window System)

add_executable(2048 src/main.cpp)

target_link_libraries(2048 SFML::Graphics SFML::Window SFML::System)
