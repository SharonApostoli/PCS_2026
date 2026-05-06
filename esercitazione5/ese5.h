#pragma once

#include <optional>
#include <vector>

//ALGORITMI SCORSA ESE 
//Adesso la copia è fatta fuori

//Bubblesort
template<typename T>
void bubblesort(std::vector<T>& vec){
    for(int i = 0; i < vec.size(); i++){
        for(int j = vec.size() - 1; j > i; j--){
            if(vec[j] < vec[j - 1]){
                T temp = vec[j];
                vec[j] = vec[j - 1];
                vec[j - 1] = temp;
            }
        }
    }
}

//Insertionsort
template<typename T>
void insertionsort(std::vector<T>& vec){
    for(int j = 1; j < vec.size(); j++){
        T key = vec[j];
        int i = j - 1;
        while(i >= 0 && vec[i] > key){
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
    
}

//Selectionsort
template<typename T>
void selectionsort(std::vector<T>& vec){
    for(int i = 0; i < vec.size(); i++){
        int min = i;
        for(int j = i + 1; j < vec.size(); j++){
            if(vec[j] < vec[min]){
                min = j;
            }
        }
        T temp = vec[i];
        vec[i] = vec[min];
        vec[min] = temp;
    }
}

//Merge
template<typename T>
void merge(std::vector<T>& vec, int sx, int cx, int dx){
    int n1 = cx - sx + 1;
    int n2 = dx - cx;
    //Ai vettori L e R metto un elemento in piu come el. "sentinella"
    std::vector<std::optional<T>> L(n1 + 1);
    std::vector<std::optional<T>> R(n2 + 1);

    for(int i = 0; i < n1; i++){
        L[i] = vec[sx + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = vec[cx + j + 1];
    }

    L[n1] = std::nullopt;
    R[n2] = std::nullopt;

    int i = 0;
    int j = 0;

    for(int k = sx; k < dx + 1; k++){
        if(!R[j].has_value() || (L[i].has_value() && *L[i] <= *R[j])){
            vec[k] = *L[i];
            i++;
        }else{
            vec[k] = *R[j];
            j++;
        }
    }
}

//Mergesort
template<typename T>
void mergesort(std::vector<T>& vecM, int sx, int dx){
    if(sx < dx){
        int cx = (sx + dx) / 2;
        mergesort(vecM, sx, cx);
        mergesort(vecM, cx + 1, dx);
        merge(vecM, sx, cx, dx);
    }
}

//Partition (per quicksort)
template<typename T>
int partition(std::vector<T>& vecQ, int sx, int dx){
    T x = vecQ[dx];
    int i = sx - 1;
    for(int j = sx; j < dx; j++){
        if(vecQ[j] <= x){
            i++;
            T temp = vecQ[i];
            vecQ[i] = vecQ[j];
            vecQ[j] = temp;
        }
    }
    T temp = vecQ[i + 1];
    vecQ[i + 1] = vecQ[dx];
    vecQ[dx] = temp;

    return i + 1;
}

//Quicksort 
template<typename T>
void quicksort(std::vector<T>& vecQ, int sx, int dx){
    if(sx < dx){
        int cx = partition(vecQ, sx, dx);
        quicksort(vecQ, sx, cx - 1);
        quicksort(vecQ, cx + 1, dx);
    }
}

//Quicksort con soglia
template<typename T>
void quicksort_soglia(std::vector<T>& vecQ, int sx, int dx){
    if(vecQ.size() <= 30){
        insertionsort(vecQ);
        return;
    }
    quicksort(vecQ, 0, vecQ.size() - 1);
}

//is_sorted
template<typename T>
bool is_sorted(const std::vector<T>& vec){
    for(int i = 0; i < vec.size() - 1; i++){
        if(vec[i] > vec[i + 1]){
            return false;
        }
    }
    return true;
}





