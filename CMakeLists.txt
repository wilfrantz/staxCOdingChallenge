cmake_minimum_required(VERSION 3.15)
project(staxList VERSION 0.0.1 LANGUAGES CXX)

# Set C++ standard to 17
set(CMAKE_CXX_STANDARD 17)

# Enable verbose Makefile if desired
option(CMAKE_VERBOSE_MAKEFILE "Verbose Makefile" ON)

# Define the source files for the library
set(SOURCE_FILES
    src/main.cpp
    src/stax.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Include directories
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set the build type to Debug if not explicitly set
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Optionally build and run tests
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    message(STATUS "Building tests ...")
    enable_testing()
    add_subdirectory(test)
    add_test(NAME ${PROJECT_NAME}_tests COMMAND test/${PROJECT_NAME}_test)
endif()
