cmake_minimum_required(VERSION 3.14)
project(calc)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Python3 REQUIRED)

set(VENV_PATH "${CMAKE_SOURCE_DIR}/venv")

set(VENV_PYTHON "${VENV_PATH}/bin/python3")

if (WIN32)
    set(VENV_PYTHON "${VENV_PATH}/Scripts/python.exe")
endif()

if (NOT EXISTS ${VENV_PATH})
    message(STATUS "Creating Python virtual environment in ${VENV_PATH}")
    execute_process(COMMAND ${Python3_EXECUTABLE} -m venv ${VENV_PATH})
    execute_process(COMMAND ${VENV_PYTHON} -m pip install --upgrade pip)
    execute_process(COMMAND ${VENV_PYTHON} -m pip install -r ${CMAKE_SOURCE_DIR}/requirements.txt)
endif()

set(Python3_EXECUTABLE ${VENV_PYTHON})

find_package(fmt CONFIG REQUIRED)

include_directories(include)
add_executable(calc
    src/main.cpp
    src/func.cpp
)
target_link_libraries(calc PRIVATE fmt::fmt)

add_custom_command(
        TARGET calc POST_BUILD
        COMMAND $<TARGET_FILE:calc>
        COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/src/viz.py
)
