# Min CMake ver
cmake_minimum_required(VERSION 3.11)

project($ENV{PROJ_NAME})

add_executable($ENV{PROJ_NAME} $ENV{PROJ_NAME}.cpp)
