cmake_minimum_required(VERSION 3.21)
project(KISS)

set(CMAKE_CXX_STANDARD 17)

add_executable(KISS main.cpp library/SufAutomat.cpp library/SufAutomat.h library/Solver.cpp library/Solver.h)
