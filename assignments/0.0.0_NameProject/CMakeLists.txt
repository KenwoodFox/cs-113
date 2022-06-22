# Minimum required CMake version
cmake_minimum_required(VERSION 3.11)

# Our project
project("name"
    DESCRIPTION "0.0.0"
    LANGUAGES CXX)

# our sources
set(SOURCES
    src/main.cpp
)

# Our target
add_executable(${PROJECT_NAME}_binary ${SOURCES})

# Include dirs
target_include_directories(${PROJECT_NAME}_binary
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
