# Define generic configurations for running cmake tests
cmake_minimum_required(VERSION 3.2)

set(This Sandbox)

project(${This} C CXX)

# Fix "missing DartConfiguration.tcl" warnings
include(CTest)

# Set config variables
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Add libraries used, but not required to test
add_subdirectory(googletest)

# Add paths to other CMakeLists.txt specifying the tests
enable_testing()
add_subdirectory(math)
