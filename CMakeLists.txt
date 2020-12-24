# cmake_minimum_required(VERSION <specify CMake version here>)
project(Gillespie_algorithm)

set(CMAKE_CXX_STANDARD 20)

add_executable(Gillespie_algorithm main.cpp myFunctions.h myFunctions.cpp gillespie.h gillespie.cpp)