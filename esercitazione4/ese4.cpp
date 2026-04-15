#include <iostream>
#include <algorithm>
#include <vector>

#include "ese4.h"
#include "timecounter.h"
#include "randfiller.h"

template<typename T>
void test_time(int lungh){
    //Definisco le variabili che mi servono per misurare il tmepo degli algoritmi
    timecounter tb, ti, ts, tsort;
    //Randfiller
    randfiller rf;

    //Definisco il vettori e lo riempio con randfill
    std::vector<T> vec(lungh);
    rf.fill(vec, -100, 100);

    //Bubblesort
    tb.tic();
    std::vector<T> vec_bubble = bubblesort(vec);
    double bubble_secs = tb.toc();
    std::cout << "BubbleSort in dim "<< lungh << " : " << bubble_secs << " secondi. \n";

    //Insertion
    ti.tic();
    std::vector<T> vec_inser = insertionsort(vec);
    double insertion_secs = ti.toc();
    std::cout << "InsertionSort in dim " << lungh << " : " << insertion_secs << " secondi. \n";

    //Selection
    ts.tic();
    std::vector<T> vec_sel = selectionsort(vec);
    double selection_secs = ts.toc();
    std::cout << "SelectionSort in dim " << lungh << " : " << selection_secs << " secondi. \n";

    //Sort
    tsort.tic();
    std::vector<T> vec_sort = vec;
    std::sort(vec_sort.begin(), vec_sort.end());
    double sort_secs = tsort.toc();
    std::cout << "Sort in dim " << lungh << " : " << sort_secs << " secondi.  \n" << "\n";
}

int main(){
    //Variabile delle varie lunghezze 
    int lungh = 8192;
    
    for(int i = 4; i <= lungh; i *= 2){
        test_time<int>(i);
    }

   return 0;
}