cmake_minimum_required(VERSION 3.7)
project(LocationRouting)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LocationRoutingSolution.cpp LocationRoutingSolution.h LocationRoutingProblem.cpp LocationRoutingProblem.h GA.cpp GA.h AE.cpp AE.h Individual.cpp Individual.h)
add_executable(LocationRouting ${SOURCE_FILES})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

