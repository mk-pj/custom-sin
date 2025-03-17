cmake_minimum_required(VERSION 3.14)
project(calc)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 6fdf225
)

FetchContent_MakeAvailable(fmt)

include_directories(include)

add_executable(calc
    src/main.cpp
    src/func.cpp
)
target_link_libraries(calc PRIVATE fmt::fmt)
