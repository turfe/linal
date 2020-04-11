cmake_minimum_required(VERSION 3.14)
project(linal)

set(CMAKE_CXX_STANDARD 14)

add_executable(linal main.cpp vector.h vectorS.cpp matrix.h matrixS.cpp)