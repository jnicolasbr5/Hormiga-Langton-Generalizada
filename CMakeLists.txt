cmake_minimum_required(VERSION 3.20)

# Project name and language
project(langton VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include folder
include_directories(include)

# List all source files
set(SOURCES
    src/main.cpp
    src/tape.cpp
    src/simulator.cpp
    src/ant.cpp
    src/ant_ddii.cpp
    src/ant_didi.cpp
    src/ant_idid.cpp
)

# Create executable
add_executable(langton2 ${SOURCES})

# Optional: compiler warnings
target_compile_options(langton2 PRIVATE -Wall -Wextra -Wpedantic)