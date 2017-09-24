cmake_minimum_required (VERSION 2.8)
project (Trias)

# set C++17
set(CMAKE_CXX_COMPILER /usr/bin/g++-7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find packages

# include directories
include_directories("include")

# add whirlwind
add_executable(trias
        src/main.cpp)

# link everything to whirlwind

# dependencies