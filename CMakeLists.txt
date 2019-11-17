cmake_minimum_required(VERSION 3.9)
project(OptimalThreshold)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(
        GrowingRegions main.cpp
        optimal_threshold.cpp
)

# linking
target_link_libraries(GrowingRegions ${OpenCV_LIBS})