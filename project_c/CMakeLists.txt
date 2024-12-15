set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare -Wno-cast-function-type -Wno-switch")

cmake_minimum_required(VERSION 3.22)

cmake_path(SET LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

include_directories(
    ${LIB_DIR}
)

add_subdirectory(src)

project(balls_project)