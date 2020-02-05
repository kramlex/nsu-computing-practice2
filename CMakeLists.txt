cmake_minimum_required(VERSION 3.15)
project(computingPractice2)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -static")

add_executable(computingPractice2 LagrangePolynomial/LagrangePolynomial.cpp)