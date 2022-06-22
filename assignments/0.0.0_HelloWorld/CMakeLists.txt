# Minimum required CMake version
cmake_minimum_required(VERSION 3.11)

# The name of our project
project($ENV{PROJ_NAME}
    DESCRIPTION "0.0.0"
    LANGUAGES CXX)

# Our target
add_executable($ENV{PROJ_NAME}_binary main.cpp
    src/printhello.cpp)

target_compile_features($ENV{PROJ_NAME}_binary PRIVATE cxx_std_20)
target_include_directories($ENV{PROJ_NAME}_binary PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
