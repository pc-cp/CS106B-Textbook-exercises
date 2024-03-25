
#include <iostream>
#include <ctime>
#include <iomanip>
#include "random.h"
#include "vector.h"
using namespace std;

const int TIMES = 100;

int binarySearch(Vector<int> &vec, int x);
int linearSearch(Vector<int> &vec, int x);
void printSearchTimer();
void sort(Vector<int> &vec);
void bucketSort(Vector<int> &vec);

int main() {
    printSearchTimer();

    return 0;
}

void printSearchTimer() {
    Vector<int> sizes = {10,
                         50,
                         100,
                         500,
                         1000,
                         5000,
                         10000,
                         50000,
                         100000};
    Vector<double> comparisonsInLinear(sizes.size(), 0), comparisonsInBinary(sizes.size(), 0);

    for(int size = 0; size < sizes.size(); ++size) {
        int n = sizes[size];

        Vector<int> vec(n, 0);
        for(int i = 0; i < n; ++i) {
            vec[i] = randomInteger(0, 999);
        }
        sort(vec);

        for(int time = 0; time < TIMES; ++time) {
            int query = randomInteger(0, 999);
            comparisonsInLinear[size] += linearSearch(vec, query);
            comparisonsInBinary[size] += binarySearch(vec, query);
        }
        comparisonsInLinear[size] /= TIMES;
        comparisonsInBinary[size] /= TIMES;
    }

    cout << setw(7) << 'N' << '|' << setw(15) << "Linear" << '|' << setw(15) << "Binary" << endl;
    cout << setw(8) << setfill('-') << "+" << setw(16) << '+' << setw(15) << '+' << endl;

    for(int i = 0; i < sizes.size(); ++i) {
        cout << fixed << setw(7) << setfill(' ') << sizes[i] << "|" << setw(15) << setprecision(1) << comparisonsInLinear[i] << "|" << setw(15) << setprecision(1) << comparisonsInBinary[i] << endl;
    }
}

int binarySearch(Vector<int> &vec, int x) {
    int counts = 0;

    int l = 0, r = vec.size()-1;
    while(l < r) {
        counts++;
        int mid = l + r >> 1;
        if(vec[mid] >= x) r = mid;
        else l = mid + 1;
    }
    // vec[l] == x ? l : -1;
    return counts;
}

int linearSearch(Vector<int> &vec, int x) {
    int counts = 0;

    int pos = 0;
    for(; pos < vec.size(); ++pos) {
        counts ++;
        if(vec[pos] == x) {
            break;
        }
    }
    // vec[pos] == x ? pos : -1;
    return counts;
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
