set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra -Wno-unused-parameter -Wno-cast-function-type -Wno-switch")

cmake_minimum_required(VERSION 3.22)

cmake_path(SET LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
cmake_path(SET INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

include_directories(
    ${LIB_DIR}
    ${INCLUDE_DIR}
)

add_subdirectory(project_c)

project(balls)