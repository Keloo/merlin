cmake_minimum_required(VERSION 3.5)
project(Merlin)

# C++11 Standard
set(CMAKE_CXX_STANDARD 11)
# Make it verbose
set(CMAKE_VERBOSE_MAKEFILE ON)

# Include dirs
include_directories("${PROJECT_SOURCE_DIR}/include")


add_library(glad include/glad/glad.h src/glad.c)

# Compiled by us
add_executable(Merlin main.cpp)

# Linkings
target_link_libraries(Merlin glad glfw GL X11 pthread Xrandr Xi dl)