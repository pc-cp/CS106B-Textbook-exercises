
#include <iostream>
#include <iomanip>
#include "vector.h"
using namespace std;

const int TIMES = 100;

void insertSort(Vector<int> &vec, int l, int r);
void quickSortAndInsertionSort(Vector<int> &vec, int l, int r,
                               int crossOverPoint);
void printSortTimer();

int main() {
    printSortTimer();
    return 0;
}

void printSortTimer() {
    Vector<int> crossOverPoints = {5,
                                  10,
                                  15,
                                  20,
                                  35,
                                  50};
    Vector<double> elapseds(crossOverPoints.size(), 0);

    for(int i = 0; i < crossOverPoints.size(); ++i) {
            int n = 50000;
            Vector<int> vec(n, 0);

            for(int time = 0; time < TIMES; ++time) {

                for(int j = 0; j < n; ++j) {
                    vec[j] = randomInteger(0, 999);
                }

                double start = double(clock()) / CLOCKS_PER_SEC;
                quickSortAndInsertionSort(vec, 0, n-1, crossOverPoints[i]);
                double finish = double(clock()) / CLOCKS_PER_SEC;
                elapseds[i] += (finish - start);
            }
        elapseds[i] /= TIMES;
    }
    cout << setw(20) <<"crossOverPoints" << '|' << setw(30) << "quickSortAndInsertionSort" << endl;
    cout << setw(21) << setfill('-') << "+" << setw(31) << '+' << endl;

    for(int i = 0; i < crossOverPoints.size(); ++i) {
        cout << fixed << setw(20) << setfill(' ') << crossOverPoints[i] << "|" << setw(30) << setprecision(5) << elapseds[i] << "|" << endl;
    }
}

void insertionSort(Vector<int> &vec, int l, int r) {
    for(int i = l; i <= r; i++) {
        for(int j = i-1; j >= l; j--) {
            if(vec[j] > vec[j+1]) {
                int tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
            }
            else {
                break;
            }
        }
    }
}

void quickSortAndInsertionSort(Vector<int> &vec, int l, int r,
                                int crossOverPoint) {
    if(l >= r) return ;

    int i = l-1 , j = r+1, pivot = vec[l + r >> 1];

    do {
        do i++; while(vec[i] < pivot);
        do j--; while(vec[j] > pivot);
        if(i < j) {
            int tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
        }
    } while(i < j);

    if(l <= j && j-l+1 <= crossOverPoint) {
        insertionSort(vec, l, j);
    }
    else {
        quickSortAndInsertionSort(vec, l, j, crossOverPoint);
    }

    if(j+1 <= r && r-j <= crossOverPoint) {
        insertionSort(vec, j+1, r);
    }
    else {
        quickSortAndInsertionSort(vec, j+1, r, crossOverPoint);
    }

}

/*
     crossOverPoints|     quickSortAndInsertionSort
--------------------+------------------------------+
                   5|                       0.02386|
                  10|                       0.02191|
                  15|                       0.02118|
                  20|                       0.02121|
                  35|                       0.02265|
                  50|                       0.02648|
*/
