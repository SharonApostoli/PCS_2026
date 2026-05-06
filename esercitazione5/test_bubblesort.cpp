#include <iostream>
#include <vector>
#include <string>

#include "ese5.h"
#include "randfiller.h"

template<typename T>
void test_bubble(int num){
    randfiller rf;
    
    std::vector<T> vec(10);
    rf.fill(vec, -100, 100);

    bubblesort(vec);
    if(is_sorted(vec) == true){
        std::cout << "Il vettore " << num << " fatto con bubblesort è ordinato. \n";
    }else{
        std::cout << "Il vettore " << num << " fatto con bubblesort non è ordinato. \n";
    }

}


int main(){
    int num = 100;
    
    //Testare algoritmi su 100 vettori di dim a caso
    for(int i = 0; i < num; i++){
        test_bubble<int>(i);
    }
    
    std::vector<std::string> vec_string = {"ciao", "sono", "sharon", "mettimi", "in", "ordine"};
    bubblesort(vec_string);
    if(is_sorted(vec_string) == true){
        std::cout << "Il vettore stringa è ordinato con bubblesort. \n";
    }else{
        std::cout << "Il vettore stringa non è ordinato con bubblesort. \n";
    }
    return 0;
}