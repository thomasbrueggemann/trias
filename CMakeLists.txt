cmake_minimum_required (VERSION 2.8)
project (Trias)

# set
set(CMAKE_CXX_COMPILER /usr/bin/g++-7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# definitions
add_definitions(-DMAGICKCORE_QUANTUM_DEPTH=16)
add_definitions(-DMAGICKCORE_HDRI_ENABLE=0)

# find packages
find_package(ImageMagick COMPONENTS Magick++)

# include directories
include_directories("include")
include_directories(${ImageMagick_INCLUDE_DIRS})

# add whirlwind
add_executable(trias
        src/main.cpp
        include/flags.h
        src/delaunay.cpp
        include/delaunay.h
        src/triangle.cpp
        include/triangle.h
        include/point.h
        src/node.cpp
        include/node.h
        src/circle.cpp
        include/circle.h
        src/edge.cpp
        include/edge.h src/sobel.cpp include/sobel.h)

# link everything to whirlwind
target_link_libraries(trias ${ImageMagick_LIBRARIES})