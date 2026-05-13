#versione cmake
cmake_minimum_required(VERSION 3.20)

#nome progetto
project(ese8)

#versione c++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARE_REQUIRED ON)

#warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

#eseguibile
add_executable(ese8 ese8.cpp)
