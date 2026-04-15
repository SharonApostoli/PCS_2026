#versione di CMake
cmake_minimum_required(VERSION 3.20)

#nome progetto
project(ese4)

#versione C++ da utilizzare
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

#creo il target per l'ese principale
#la cosa sritta è una variabile, e dopo ci sta scritto il "valore" della var
set(SRC_test_sorts timecounter.cpp ese4.cpp) 
add_executable(ese4 ${SRC_test_sorts})


#target per gli eseguibili dei test unitari
#bubblesort
add_executable(test_bubblesort test_bubblesort.cpp)
add_test(NAME bubblesort COMMAND test_bubblesort)

#insertionsort
add_executable(test_insertionsort test_insertionsort.cpp)
add_test(NAME insertionsort COMMAND test_insertionsort)

#selectionsort
add_executable(test_selectionsort test_selectionsort.cpp)
add_test(NAME selectionsort COMMAND test_selectionsort)

enable_testing()

