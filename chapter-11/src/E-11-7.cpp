
/* E-11-7.cpp
 * Rewrite the implementation of the merge sort algorithm from Figure 10-3 so that it sorts an array rather than a vector.
 */

#include <iostream>
#include "vector.h"

using namespace std;

void sort(int array[], int n);
void mergeSort(int array[], int l, int r);

int main() {
    int array[] = {5, 3, 1, 4, 2};

    sort(array, 5);

    for(int elem: array) {
        cout << elem << ' ';
    }
    return 0;
}


void sort(int array[], int n) {
    mergeSort(array, 0, n-1);
}
void mergeSort(int array[], int l, int r) {
    if(l >= r) return ;

    int mid = l + r >> 1;

    mergeSort(array, l, mid);
    mergeSort(array, mid+1, r);

    Vector<int> auxiliaryArray;

    int i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(array[i] <= array[j]) {
            auxiliaryArray += array[i++];
        }
        else {
            auxiliaryArray += array[j++];
        }
    }

    while(i <= mid) {
        auxiliaryArray += array[i++];
    }

    while(j <= r) {
        auxiliaryArray += array[j++];
    }

    int k = l;
    for(int elem : auxiliaryArray) {
        array[k++] = elem;
    }

}
