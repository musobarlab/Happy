cmake_minimum_required (VERSION 3.10)

# Define the project
project(happy)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_FLAGS " -std=c++14 -funroll-loops -O3 -march=native")

MESSAGE( [Main] " PROJECT_NAME = ${PROJECT_NAME}")
MESSAGE( [Main] " CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
MESSAGE( [Main] " CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
MESSAGE( [Main] " PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")

# ------------- Glad -------------
set(GLAD_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/vendor/glad/include/)

# ------------- SDL2 -------------
find_package(SDL2 REQUIRED)

include_directories(
    ${GLAD_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} Src/Main.cpp)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})