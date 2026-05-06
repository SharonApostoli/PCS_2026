#include <iostream>
#include <vector>
#include <string>

#include "ese5.h"
#include "randfiller.h"

template<typename T>
void test_mergesort(int num){
    randfiller rf;

    std::vector<T> vec(num);
    rf.fill(vec, -100, 100);

    mergesort(vec, 0, vec.size() - 1);
    if(is_sorted(vec) == true){
        std::cout << "Il vettore " << num << " fatto con mergesort è ordinato. \n";
    }else{
        std::cout << "Il vettore " << num << " fatto con mergesort non è ordinato. \n";
    }
}

int main(){
    int num = 100;

    for(int i = 1; i < num; i++){
        test_mergesort<int>(i);
    }

    std::vector<std::string> vec_string = {"ciao", "sono", "sharon", "mettimi", "in", "ordine"};
    mergesort(vec_string, 0, vec_string.size() - 1);
    if(is_sorted(vec_string) == true){
        std::cout << "Il vettore stringa è ordinato con mergesort. \n";
    }else{
        std::cout << "Il vettore stringa non è ordinato con mergesort. \n";
    }
    return 0;
}