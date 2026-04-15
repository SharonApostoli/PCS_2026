#pragma once

#include <optional>
#include <vector>

//bubblesort
template<typename T>
std::vector<T> bubblesort(const std::vector<T>& vecB){
    std::vector<T> vec = vecB;
    for(size_t i = 0; i < vec.size(); i++){
        for(size_t j = vec.size() - 1; j > i; j--){
            if(vec[j] < vec[j - 1]){
                T temp = vec[j];
                vec[j] = vec[j - 1];
                vec[j - 1] = temp;
            }
        }
    }
    return vec;
}

//insertionsort
template<typename T>
std::vector<T> insertionsort(const std::vector<T>& vecI){
    std::vector<T> vec = vecI;
    for(int j = 1; j < vec.size(); j++){
        T key = vec[j];
        int i = j - 1;
        while(i >= 0 && vec[i] > key){
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
    return vec;
}

//selectionsort
template<typename T>
std::vector<T> selectionsort(const std::vector<T>& vecS){
    std::vector<T> vec = vecS;
    for(size_t i = 0; i < vec.size(); i++){
        int min = i;
        for(size_t j = i + 1; j < vec.size(); j++){
            if(vec[j] < vec[min]){
                min = j;
            }
        }
        T temp = vec[i];
        vec[i] = vec[min];
        vec[min] = temp;
    }
    return vec;
}

//is_sorted
template<typename T>
bool is_sorted(const std::vector<T>& vec){
    for(size_t i = 0; i < vec.size() - 1; i++){
        if(vec[i] > vec[i + 1]){
            return false;
        }
    }
    return true;
}