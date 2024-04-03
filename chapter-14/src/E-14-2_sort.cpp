
#ifndef _mysort_h
#define _mysort_h

#include "vector.h"

template <typename ValueType>
void mySort(Vector<ValueType> &vec) {
    quickSort(vec, 0, vec.size()-1);
}

template <typename ValueType>
void mySwap(ValueType &a, ValueType &b) {
    ValueType tmp = a;
    a = b;
    b = tmp;
}


template <typename ValueType>
void quickSort(Vector<ValueType> &vec, int l, int r) {
    if(l >= r) {
        return ;
    }

    int i = l-1, j = r+1;
    ValueType pivot = vec[(l + r) >> 1];

    do {
        do i ++; while(vec[i] < pivot);
        do j --; while(vec[j] > pivot);
        if(i < j) mySwap(vec[i], vec[j]);
    }while(i < j);

    /*
     * [i, i-1] <= pivot, [j+1, r] >= pivot
     * i >= j, vec[i] >= pivot, vec[j] <= pivot
     *
     * i == j: [i, j] <= pivot, [j+1, r] >= pivot
     * i > j : [i, j] <= pivot, [j+1, r] >= pivot
    */
    quickSort(vec, l, j);
    quickSort(vec, j+1, r);
}

#endif
