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

# Set the build type to Debug if not explicitly set
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Optionally build and run tests
option(BUILD_TESTS "Build tests" ON)

# Link with GTest and GTest main if tests are enabled
if(BUILD_TESTS)
    message(STATUS "Building tests ...")
    enable_testing()

    # Add GTest dependency
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    # Add test executable
    add_executable(${PROJECT_NAME}_test ${CMAKE_CURRENT_SOURCE_DIR}/test/src/UT_Stax_Test.cpp)
    target_link_libraries(staxList_test GTest::GTest GTest::Main)

    # Add test
    add_test(NAME staxList_tests COMMAND staxList_test)
endif()
