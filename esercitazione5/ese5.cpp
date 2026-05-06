#include <iostream>
#include <algorithm>
#include <vector>

#include "ese5.h"
#include "timecounter.h"
#include "randfiller.h"

template<typename T>
void time_bubble(std::vector<std::vector<T>>& vec){
    //Var tempo
    timecounter tb;
    tb.tic();
    for(int i = 0; i < vec.size(); i++){
        bubblesort(vec[i]);
    }
    double tot_t_bub = tb.toc();
    double t_med_bub = tot_t_bub / vec.size();
    std::cout << "Tempo medio su 100 vettori di dim: " << vec[0].size() << " BubbleSort: " << t_med_bub << " s. \n";
}

template<typename T>
void time_insertion(std::vector<std::vector<T>>& vec){
    timecounter ti;
    ti.tic();
    for(int i = 0; i < vec.size(); i++){
        insertionsort(vec[i]);
    }
    double tot_t_ins = ti.toc();
    double t_med_ins = tot_t_ins / vec.size();
    std::cout << "Tempo medio su 100 vettori di dim: " << vec[0].size() << " InsertionSort: " << t_med_ins << " s. \n";
}

template<typename T>
void time_selection(std::vector<std::vector<T>>& vec){
    timecounter ts;
    ts.tic();
    for(int i = 0; i < vec.size(); i++){
        selectionsort(vec[i]);
    }
    double tot_t_sel = ts.toc();
    double t_med_sel = tot_t_sel / vec.size();
    std::cout << "Tempo medio su 100 vettori di dim: " << vec[0].size() << " SelectionSort: " << t_med_sel << " s. \n";
}

template<typename T>
void time_merge(std::vector<std::vector<T>>& vec){
    timecounter tm;
    tm.tic();
    for(int i = 0; i < vec.size(); i++){
        mergesort(vec[i], 0, vec[i].size() - 1);
    }
    double tot_t_mer = tm.toc();
    double t_med_mer = tot_t_mer / vec.size();
    std::cout << "Tempo medio su 100 vettori di dim: " << vec[0].size() << " MergeSort: " << t_med_mer << " s. \n";
}

template<typename T>
void time_quick(std::vector<std::vector<T>>& vec){
    timecounter tq;
    tq.tic();
    for(int i = 0; i < vec.size(); i++){
        quicksort_soglia(vec[i], 0, vec[i].size() - 1);
    }
    double tot_t_qui = tq.toc();
    double t_med_qui = tot_t_qui / vec.size();
    std::cout << "Tempo medio su 100 vettori di dim: " << vec[0].size() << " QuickSort: " << t_med_qui << " s. \n";
}

template<typename T>
void time_sort(std::vector<std::vector<T>>& vec){
    timecounter tsort;
    tsort.tic();
    for(int i = 0; i < vec.size(); i++){
        std::sort(vec.begin(), vec.end());
    }
    double tot_t_sort = tsort.toc();
    double t_med_sort = tot_t_sort / vec.size();
    std::cout << "Tempo medio su 100 vettori di dim: " << vec[0].size() << " Sort: " << t_med_sort << " s. \n \n";
}

int main(){
    /*Questo for loop mi serve per poter visualizzare la dimensione sotto la quale gli algoritmi
    quadratici sono piu veloci dei vettori logaritmici*/
    for(int d = 1; d <= 100; d++){
        //Prealloca un 100 di vettori di dim a scelta (facciamo crescente fino a 100)
        std::vector<std::vector<int>> vec(100, std::vector<int>(d));
        //Riempio i vettori
        randfiller rf;
        for(int i = 0; i < vec.size(); i++){
            rf.fill(vec[i], -100, 100);
        }

        //Prima copio tutti i vettori, cosi da avere una misura del tempo piu precisa
        std::vector<std::vector<int>> vec_m = vec;
        std::vector<std::vector<int>> vec_q = vec;
        std::vector<std::vector<int>> vec_b = vec;
        std::vector<std::vector<int>> vec_i = vec;
        std::vector<std::vector<int>> vec_s = vec;
        std::vector<std::vector<int>> vec_sort = vec;

        time_bubble(vec_b);
        time_insertion(vec_i);
        time_selection(vec_s);
        time_merge(vec_m);
        time_quick(vec_q);
        time_sort(vec_sort);
    

    }

    return 0;
}