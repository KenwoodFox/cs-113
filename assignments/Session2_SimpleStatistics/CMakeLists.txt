# Minimum required CMake version
cmake_minimum_required(VERSION 3.11)

# Our project
project("SimpleStatistics"
    DESCRIPTION "Session2"
    LANGUAGES CXX)

# our sources
set(SOURCES
    src/main.cpp
)

# Get the latest commit hash
execute_process(
    COMMAND python ../Shared/buildVars.py
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE MOTD
    OUTPUT_STRIP_TRAILING_WHITESPACE)

# Our target
add_executable(${PROJECT_NAME}_binary ${SOURCES})

# Add hash
target_compile_definitions(${PROJECT_NAME}_binary PRIVATE
    "-DMOTD=\"${MOTD}\"")

# Include dirs
target_include_directories(${PROJECT_NAME}_binary
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
