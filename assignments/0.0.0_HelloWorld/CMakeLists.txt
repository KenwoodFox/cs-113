# Minimum required CMake version
cmake_minimum_required(VERSION 3.11)

# The name of our project
project($ENV{PROJ_NAME}
    DESCRIPTION "0.0.0"
    LANGUAGES CXX)

# our sources
set(SOURCES
    src/printhello.cpp
    main.cpp
)

# Our target
add_executable($ENV{PROJ_NAME}_binary ${SOURCES})

# Include dirs
target_include_directories($ENV{PROJ_NAME}_binary
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# Clang tidy
set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,readability-*)
