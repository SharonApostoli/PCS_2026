#versione cmake
cmake_minimum_required(VERSION 3.20)

#nome progetto
project(ese5)

#versione c++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REUIRED ON)

#warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

#target ese principale
set(SRC_test_sorts timecounter.cpp ese5.cpp)
add_executable(ese5 ${SRC_test_sorts})

#bubblesort
add_executable(test_bubblesort test_bubblesort.cpp)
add_test(NAME bubblesort COMMAND test_bubblesort)

#insertionsort
add_executable(test_insertionsort test_insertionsort.cpp)
add_test(NAME insertionsort COMMAND test_insertionsort)

#selectionsort
add_executable(test_selectionsort test_selectionsort.cpp)
add_test(NAME selectionsort COMMAND test_selectionsort)

#mergesort
add_executable(test_mergesort test_mergesort.cpp)
add_test(NAME mergesort COMMAND test_mergesort)

#quicksort
add_executable(test_quicksort test_quicksort.cpp)
add_test(NAME quicksort COMMAND test_quicksort)

enable_testing()