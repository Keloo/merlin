cmake_minimum_required(VERSION 3.5)
project(Merlin)

# C++11 Standard
set(CMAKE_CXX_STANDARD 14)
# Make it verbose
set(CMAKE_VERBOSE_MAKEFILE ON)

# Include dirs
include_directories("${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/src")

add_library(glad include/glad/glad.h src/glad.c)

file(GLOB SOURCES "src/*.cpp")

# Compiled by us
add_executable(Merlin ${SOURCES} "main.cpp")

# Linkings
target_link_libraries(Merlin glad glfw GL X11 pthread Xrandr Xi dl)