#specifico versione CMake
cmake_minimum_required(VERSION 3.20)

#specifico il nome del progetto
project(ese3)

#specifico la versione di C++ da utilizzare
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REUIRED ON)

#incremento i livelli di warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

#dichiaro l'eseguibile
add_executable(ese3 ese3.cpp ese3_func.cpp)