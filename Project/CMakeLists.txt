cmake_minimum_required(VERSION 3.10)
project(HardwareInventory)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Includes
include_directories(include)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Executable
add_executable(HardwareInventory main.cpp ${SOURCES})

# Future: Link Google Test here for ProjectTester
