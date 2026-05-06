#include <iostream>
#include <vector>
#include <string>

#include "ese5.h"
#include "randfiller.h"

template<typename T>
void test_quicksort(int num){
    randfiller rf;

    std::vector<T> vec(num);
    rf.fill(vec, -100, 100);

    quicksort(vec, 0, vec.size() - 1);
    if(is_sorted(vec) == true){
        std::cout << "Il vettore " << num << " fatto con quicksort è ordinato. \n";
    }else{
        std::cout << "Il vettore " << num << " fatto con quicksort non è ordinato. \n";
    }
}

int main(){
    int num = 100;

    for(int i = 1; i < num; i++){
        test_quicksort<int>(i);
    }

    std::vector<std::string> vec_string = {"ciao", "sono", "sharon", "mettimi", "in", "ordine"};
    quicksort(vec_string, 0, vec_string.size() - 1);
    if(is_sorted(vec_string) == true){
        std::cout << "Il vettore stringa è ordinato con quicksort. \n";
    }else{
        std::cout << "Il vettore stringa non è ordinato con quicksort. \n";
    }
    return 0;
}