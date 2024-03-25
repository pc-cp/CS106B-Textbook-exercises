
#include <iostream>
#include <iomanip>
#include "vector.h"
using namespace std;

const int TIMES = 100;

void quickSort1(Vector<int> &vec, int l, int r);
void quickSort2(Vector<int> &vec, int l, int r);
void quickSort3(Vector<int> &vec, int l, int r);
void insertSort(Vector<int> &vec, int l, int r);
void quickSortAndInsertionSort(Vector<int> &vec, int l, int r,
                               int crossOverPoint);
void selectionSort(Vector<int>& vec, int l, int r);
void quickSortAndSelectionSort(Vector<int> &vec, int l, int r,
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
                quickSortAndSelectionSort(vec, 0, n-1, crossOverPoints[i]);
                double finish = double(clock()) / CLOCKS_PER_SEC;
                elapseds[i] += (finish - start);
            }
        elapseds[i] /= TIMES;
    }
    cout << setw(20) <<"crossOverPoints" << '|' << setw(30) << "quickSortAndSelectionSort" << endl;
    cout << setw(21) << setfill('-') << "+" << setw(31) << '+' << endl;

    for(int i = 0; i < crossOverPoints.size(); ++i) {
        cout << fixed << setw(20) << setfill(' ') << crossOverPoints[i] << "|" << setw(30) << setprecision(5) << elapseds[i] << "|" << endl;
    }
}

void quickSort1(Vector<int> &vec, int l, int r) {
    if(l >= r) return ;

    int i = l, j = r, pivot = vec[l];

    do {
        do i++; while(i < r && vec[i] < pivot);
        do j--; while(j > l && vec[j] > pivot);
        if(i < j) {
            int tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
        }
    } while(i < j);

    int tmp = vec[l];
    vec[l] = vec[j];
    vec[j] = tmp;

    quickSort1(vec, l, j);
    quickSort1(vec, j+1, r);
}

void quickSort2(Vector<int> &vec, int l, int r) {
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

    quickSort2(vec, l, j);
    quickSort2(vec, j+1, r);
}

void quickSort3(Vector<int> &vec, int l, int r) {
    if(l >= r) return ;

    int arr[3];
    arr[0] = vec[l];
    arr[1] = vec[r];
    arr[2] = vec[l + r >> 1];

    for(int i = 0; i < 3; ++i) {
        for(int j = i-1; j >= 0; j--) {
            if(arr[j] > arr[j+1]) {
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
            else {
                break;
            }
        }
    }

    int i = l-1 , j = r+1, pivot = arr[1];

    do {
        do i++; while(i <= r && vec[i] < pivot);
        do j--; while(j >= l && vec[j] > pivot);
        if(i < j) {
            int tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
        }
    } while(i < j);

    quickSort3(vec, l, j);
    quickSort3(vec, j+1, r);
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

void selectionSort(Vector<int>& vec, int l, int r) {
    for(int lh = l; lh <= r; lh++) {
        int rh = lh;
        for(int i = lh+1; i <= r; ++i) {
            if(vec[i] < vec[rh]) {
                rh = i;
            }
        }
        int tmp = vec[lh];
        vec[lh] = vec[rh];
        vec[rh] = tmp;
    }
}

void quickSortAndSelectionSort(Vector<int> &vec, int l, int r,
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
        selectionSort(vec, l, j);
    }
    else {
        quickSortAndSelectionSort(vec, l, j, crossOverPoint);
    }

    if(j+1 <= r && r-j <= crossOverPoint) {
        selectionSort(vec, j+1, r);
    }
    else {
        quickSortAndSelectionSort(vec, j+1, r, crossOverPoint);
    }

}




/*
     crossOverPoints|     quickSortAndSelectionSort
--------------------+------------------------------+
                   5|                       0.02659|
                  10|                       0.02625|
                  15|                       0.02714|
                  20|                       0.02823|
                  35|                       0.03218|
                  50|                       0.03713|
*/
