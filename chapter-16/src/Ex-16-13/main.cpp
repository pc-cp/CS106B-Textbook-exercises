
#include <iostream>
#include "vector.h"
#include "random.h"
using namespace std;

template <typename ValueType>
void sort(Vector<ValueType> &vec);

template <typename ValueType>
void heapSort(Vector<ValueType> &vec);

template <typename ValueType>
void down(Vector<ValueType> &vec, int index, int count);


int main() {
    Vector<int> vec;
    vec.add(-1);
    for(int i = 1; i <= 9; ++i) {
        vec.add(randomInteger(0, 100));
    }

    for(int i = 1; i <= 9; ++i) {
        cout << vec[i] << ' ';
    }
    cout << endl;

    sort(vec);

    for(int i = 1; i <= 9; ++i) {
        cout << vec[i] << ' ';
    }
    cout << endl;
    return 0;
}




template <typename ValueType>
void sort(Vector<ValueType> &vec) {
    heapSort(vec);
}

template <typename ValueType>
void heapSort(Vector<ValueType> &vec) {
    int len = vec.size()-1;
    int count = len;

    for(int i = len/2; i >= 1; i--) down(vec, i, count);
    while(len--) {
        std::swap(vec[1], vec[count]);
        count--;
        down(vec, 1, count);
    }
}

template <typename ValueType>
void down(Vector<ValueType> &vec, int index, int count) {
    int t = index;
    if(2*index <= count && vec[2*index] > vec[t]) t = 2*index;
    if(2*index+1 <= count && vec[2*index+1] > vec[t]) t = 2*index+1;
    if(t != index) {
        std::swap(vec[t], vec[index]);
        down(vec, t, count);
    }
}



