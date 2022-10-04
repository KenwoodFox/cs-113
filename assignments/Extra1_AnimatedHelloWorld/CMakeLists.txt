# Minimum required CMake version
cmake_minimum_required(VERSION 3.11)

# Our project
project("AnimatedHelloWorld"
    DESCRIPTION "Extra1"
    LANGUAGES CXX)

# libigl
add_subdirectory(libigl) # (Included as a submodule)

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
    ${PROJECT_SOURCE_DIR}/include/HelloWorldLib
)

# Link libs
target_link_libraries(${PROJECT_NAME}_binary igl::core)
