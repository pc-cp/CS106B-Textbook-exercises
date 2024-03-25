
#include <iostream>
#include <ctime>
#include <iomanip>
#include "random.h"
#include "vector.h"
using namespace std;
const int TIMES = 100;

void sort(Vector<int> &vec);
void insertionSort(Vector<int> &vec);
void bucketSort(Vector<int> &vec);
void printSortTimer();

int main() {
    printSortTimer();

    return 0;
}

void printSortTimer() {
    Vector<int> sizes = {10,
                         50,
                         100,
                         500,
                         1000,
                         5000/*,
                         10000,
                         50000,
                         100000*/};
    Vector<double> elapseds;

    for(int size: sizes) {
        Vector<int> vec(size, 0);
        double start = double(clock()) / CLOCKS_PER_SEC;

        for(int time = 0; time < TIMES; ++time) {
            for(int i = 0; i < size; ++i) {
                vec[i] = randomInteger(0, 999);
            }
            sort(vec);
        }

        double finish = double(clock()) / CLOCKS_PER_SEC;
        elapseds.add((finish - start)/TIMES);
    }
    cout << setw(7) << ' ' << '|' << setw(15) << "Time(msec)" << endl;
    cout << setw(7) << setfill('-') << '-' << "+" << setw(15) << '-' << endl;

    for(int i = 0; i < sizes.size(); ++i) {
        cout << fixed << setw(7) << setfill(' ') << sizes[i] << "|" << setw(15) << setprecision(5) << elapseds[i] << endl;
    }
}


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

void bucketSort(Vector<int> &vec) {

    vector<int> buckets(1000, 0);
    for(auto elem : vec) {
        buckets[elem] ++;
    }

    int pos = 0;
    for(int i = 0; i < 1000; ++i) {
        for(int j = 0; j < buckets[i]; ++j) {
            vec[pos++] = i;
        }
    }

}


void sort(Vector<int> &vec) {
    // insertionSort(vec);
    bucketSort(vec);
}

