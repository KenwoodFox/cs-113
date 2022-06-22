# Minimum required CMake version
cmake_minimum_required(VERSION 3.11)

# Our project
project("hello"
    DESCRIPTION "0.0.0"
    LANGUAGES CXX)

# our sources
set(SOURCES
    src/printhello.cpp
    src/main.cpp
)

# Our target
add_executable(${PROJECT_NAME}_binary ${SOURCES})

# Include dirs
target_include_directories(${PROJECT_NAME}_binary
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
