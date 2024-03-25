
#include <iostream>
#include "vector.h"

using namespace std;

void sort(Vector<int> &vec);

int main() {

    Vector<int> vec = {5, 3, 2, 4, 1};
    sort(vec);
    for(int elem : vec) {
        cout << elem << ' ';
    }
    cout << endl;
    return 0;
}


/*
 * Function: sort
 * --------------
 * This implementation uses an algorithm called selection sort, which can
 * be described as follow. With your left hand(lh), point at each elemet
 * in the vector in trun, starting at index 0, At each step in the cycle:
 * 1. Find the smallest element in the range between your left hand and the
 *          end of the vector, and point at that element with your right hand(rh).
 * 2. Move that element into its correct position by exchanging the elements
 *          indicated by your left and right hands.
 */
void sort(Vector<int> &vec) {
    int n = vec.size();
    for(int lh = 0; lh < n; ++lh) {
        int rh = lh;
        for(int i = lh + 1; i < n; ++i) {
            if(vec[i] < vec[rh]) rh = i;
        }

        int tmp = vec[rh];
        vec[rh] = vec[lh];
        vec[lh] = tmp;
    }
}
