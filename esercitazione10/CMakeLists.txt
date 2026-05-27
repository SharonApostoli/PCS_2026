#verisone CMake
cmake_minimum_required(VERSION 3.20)

#nome progetto
project(ese10)

#versione c++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

#eseguibile
add_executable(ese10 ese10.cpp)

#aggiungo Eigen
target_include_directories(ese10 PRIVATE /usr/include/eigen3)