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

enable_testing()

# Add paths to other CMakeLists.txt specifying the tests
add_subdirectory(googletest)
add_subdirectory(math)
