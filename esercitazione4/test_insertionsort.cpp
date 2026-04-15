#include <iostream>
#include <vector>
#include <string>

#include "ese4.h"
#include "randfiller.h"

template<typename T>
void test_insertion(int num){
    randfiller rf;
    
    std::vector<T> vec(10);
    rf.fill(vec, -100, 100);

    std::vector<T> vec_ord = insertionsort(vec);
    if(is_sorted(vec_ord) == true){
        std::cout << "Il vettore " << num << " fatto con insertionsort è ordinato. \n";
    }else{
        std::cout << "Il vettore " << num << " fatto con insertionsort non è ordinato. \n";
    }

}

int main(){
    int num = 100;

    //Testare algoritmi su 100 vettori di dim a caso
    for(int i = 0; i < num; i++){
        test_insertion<int>(i);
    }

    std::vector<std::string> vec_string = {"ciao", "sono", "sharon", "mettimi", "in", "ordine"};
    std::vector<std::string> vec_ord = insertionsort(vec_string);
    if(is_sorted(vec_ord) == true){
        std::cout << "Il vettore stringa è ordinato con insertionsort. \n";
    }else{
        std::cout << "Il vettore stringa non è ordinato con insertionsort. \n";
    }
    return 0;
}