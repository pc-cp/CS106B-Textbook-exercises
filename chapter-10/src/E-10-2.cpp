// E-10-2.cpp
#include <iostream>
#include "vector.h"
using namespace std;

// Sorts a vector of integers in ascending order using the insertion sort algorithm.
void insertionSort(Vector<int> &vec) {
    int n = vec.size(); // Get the number of elements in the vector.

    // Loop over each element in the vector starting from the first element.
    for(int i = 0; i < n; ++i) {
        // Compare the current element to its predecessors.
        // If the current element is smaller than its predecessor, compare it to the elements before.
        // Move the elements one position up to make space for the swapped element.
        for(int j = i-1; j >= 0; j--) {
            if(vec[j] > vec[j+1]) {
                // Swap vec[j+1] and vec[j] if they are in the wrong order.
                int tmp = vec[j+1];
                vec[j+1] = vec[j];
                vec[j] = tmp;
            }
            else {
                // If the current element is greater than its predecessor, it's in the right place.
                // Since the elements before vec[j] are already sorted, no further comparisons are needed.
                break;
            }
        }
    }
}


void sort(Vector<int> &vec) {
    insertionSort(vec);
}

int main() {
    Vector<int> vec;
    while(true) {
        int elem;
        cin >> elem;
        // Exit when the input is -1
        if(elem == -1) {
            break;
        }
        vec.add(elem);
    }

    sort(vec);
    for(auto elem : vec) {
        cout << elem << ' ';
    }
    cout << endl;

    return 0;
}
