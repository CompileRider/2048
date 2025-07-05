cmake_minimum_required(VERSION 3.1.0)
project(2048)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.6.2 REQUIRED COMPONENTS graphics window system)

add_executable(2048 src/main.cpp)

target_link_libraries(2048 sfml-graphics sfml-window sfml-system)