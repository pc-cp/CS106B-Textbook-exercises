
#include <iostream>
#include "vector.h"

using namespace std;

int findMajorityElement(Vector<int> & vec);


int main() {

    Vector<int> d1;
    d1 += 3, 5, 9, 5, 5, 2, 5;
    cout << "input data: " << d1 << endl;
    cout << "majority element: " << findMajorityElement(d1) << endl << endl;

    Vector<int> d2;
    d2 += 3, 560, 1, 99999, 2, 1;
    cout << "input data: " << d2 << endl;
    cout << "majority element: " << findMajorityElement(d2) << endl << endl;

    Vector<int> d3;
    d3 += 9, 3, 7, 4, 3, 3, 3;
    cout << "input data: " << d3 << endl;
    cout << "majority element: " << findMajorityElement(d3) << endl << endl;

    return 0;
}

// reference: https://leetcode.cn/problems/majority-element/solutions/147178/3xing-c-ha-xi-z-by-zrita
// Finds the majority element in a vector of integers.
// A majority element is an element that appears more than n/2 times in the array,
// where n is the size of the array. If no such element exists, the function returns -1.
/*
 * vec = {1, 2, 3, 2, 2, 2, 5, 4, 2}
 * ---------------------------------
 *      8       4       2       1
 *    ------------------------------
 * 1: | 0       0       0       1
 * 2: | 0       0       1       0
 * 3: | 0       0       1       1
 * 2: | 0       0       1       0
 * 2: | 0       0       1       0
 * 2: | 0       0       1       0
 * 5: | 0       1       0       1
 * 4: | 0       1       0       0
 * 2: | 0       0       1       0
 */
int findMajorityElement(Vector<int> &vec) {
    int res = 0; // Initialize the result to 0.

    // Iterate over each bit position (0 to 31) for a 32-bit integer.
    for(int i = 0; i < 32; ++i) {
        int ones = 0; // Count the number of 1s in the ith bit position across all elements.
        for(int elem: vec) {
            // Right shift the element by i positions and check if the least significant bit is 1.
            ones += (elem >> i) & 1;
        }
        // If the number of 1s is more than half the size of the vector, set the ith bit in the result.
        // This is done by left shifting 1 by i positions if ones > vec.size()/2.
        res += (ones > vec.size()/2) << i;
    }

    // Verify that the computed result is indeed a majority element by counting its occurrences.
    int counts = 0; // Count the occurrences of the result in the vector.
    for(int elem: vec) {
        if(elem == res) {
            counts++;
        }
    }
    // If the count of the result is more than half the size of the vector, return the result.
    // Otherwise, return -1 indicating that there is no majority element.
    return (counts > vec.size()/2) ? res : -1;
}
