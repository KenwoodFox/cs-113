project($ENV{PROJ_NAME})

# Add lib
add_library(helloLib printhello.cpp)

# Make include dirs public
target_include_directories(helloLib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
