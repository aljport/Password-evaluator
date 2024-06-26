#include <iostream>
#include <vector>
#include <string>
#include "mergeSort.h"
using namespace std;

// Written by Alice Zhang
// referenced from slides 6 - Sorting pg. 88-90
void mergeSort::merge(std::vector<string>& vec, int beg, int mid, int end){
    // creating two halves of vector
    std::vector<string> begHalf(vec.begin() + beg, vec.begin() + mid + 1);
    std::vector<string> endHalf(vec.begin() + mid + 1, vec.begin() + end + 1);

    int i = 0, j = 0, k = beg;
    // sorting components while in individual size, merging back into original vector in alphabetical order
    while(i < begHalf.size() && j < endHalf.size()){
        if(begHalf[i] <= endHalf[j]){
            vec[k] = begHalf[i];
            i++;
        }
        else{
            vec[k] = endHalf[j];
            j++;
        }
        k++;
    }
    while(i < begHalf.size()){
        vec[k] = begHalf[i];
        i++;
        k++;
    }
    while(j < endHalf.size()){
        vec[k] = endHalf[j];
        j++;
        k++;
    }
}

// recursive function to merge sort by reference
void mergeSort::mSort(std::vector<string>& vec, int beg, int end){
    if(beg < end){
        int mid = (beg + end) / 2;
        mSort(vec, beg, mid);
        mSort(vec, mid + 1, end);
        merge(vec, beg, mid, end);
    }
}
