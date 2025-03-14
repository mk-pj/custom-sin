cmake_minimum_required(VERSION 3.14)
project(sin_calc)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(fmt CONFIG REQUIRED)

add_executable(calc custom_sin.cpp)
target_link_libraries(calc PRIVATE fmt::fmt)
