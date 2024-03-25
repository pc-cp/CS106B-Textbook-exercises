
#include <iostream>
#include <iomanip>
#include "vector.h"
using namespace std;

const int TIMES = 100;

void quickSort1(Vector<int> &vec, int l, int r, int crossOverPoint);
void quickSort2(Vector<int> &vec, int l, int r, int crossOverPoint);
void quickSort3(Vector<int> &vec, int l, int r, int crossOverPoint);
void insertionSort(Vector<int> &vec, int l, int r);
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
                         5000,
                         10000,
                         50000/*,
                         100000*/};
    Vector<double> elapseds1(sizes.size(), 0), elapseds2(sizes.size(), 0), elapseds3(sizes.size(), 0);
    int crossOverPoint = 15;

    for(int i = 0; i < sizes.size(); ++i) {
        int n = sizes[i];
        Vector<int> vec(n, 0);
        for(int time = 0; time < TIMES; ++time) {

            for(int j = 0; j < n; ++j) {
                vec[j] = randomInteger(0, 999);
            }

            Vector<int> vecCp = vec;
            double start = double(clock()) / CLOCKS_PER_SEC;
            quickSort1(vecCp, 0, n, crossOverPoint);
            double finish = double(clock()) / CLOCKS_PER_SEC;
            elapseds1[i] += (finish - start);

            vecCp = vec;
            start = double(clock()) / CLOCKS_PER_SEC;
            quickSort2(vecCp, 0, n-1, crossOverPoint);
            finish = double(clock()) / CLOCKS_PER_SEC;
            elapseds2[i] += (finish - start);

            vecCp = vec;
            start = double(clock()) / CLOCKS_PER_SEC;
            quickSort3(vecCp, 0, n-1, crossOverPoint);
            finish = double(clock()) / CLOCKS_PER_SEC;
            elapseds3[i] += (finish - start);
        }

        elapseds1[i] /= TIMES;
        elapseds2[i] /= TIMES;
        elapseds3[i] /= TIMES;

    }
    cout << setw(7) <<'N' << '|' << setw(15) << "quickSort1" << '|' << setw(15) << "quickSort2" << '|' << setw(15) << "quickSort3" << endl;
    cout << setw(8) << setfill('-') << "+" << setw(16) << '+' << setw(16) << '+' << setw(16) << '+' << endl;

    for(int i = 0; i < sizes.size(); ++i) {
        cout << fixed << setw(7) << setfill(' ') << sizes[i] << "|" << setw(15) << setprecision(5) << elapseds1[i] << "|" << setw(15) << setprecision(5) << elapseds2[i] << "|" << setw(15) << setprecision(5) << elapseds3[i] << '|' << endl;
    }
}

void quickSort1(Vector<int> &vec, int l, int r, int crossOverPoint) {
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

    // quickSort1(vec, l, j);
    // quickSort1(vec, j+1, r);
    if(l <= j && j-l <= crossOverPoint) {
        insertionSort(vec, l, j-1);
    }
    else {
        quickSort1(vec, l, j, crossOverPoint);
    }

    if(j+1 <= r && r-j-1 <= crossOverPoint) {
        insertionSort(vec, j+1, r-1);
    }
    else {
        quickSort1(vec, j+1, r, crossOverPoint);
    }

}



void quickSort2(Vector<int> &vec, int l, int r, int crossOverPoint) {
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

    // quickSort2(vec, l, j);
    // quickSort2(vec, j+1, r);
    if(l <= j && j-l+1 <= crossOverPoint) {
        insertionSort(vec, l, j);
    }
    else {
        quickSort2(vec, l, j, crossOverPoint);
    }

    if(j+1 <= r && r-j <= crossOverPoint) {
        insertionSort(vec, j+1, r);
    }
    else {
        quickSort2(vec, j+1, r, crossOverPoint);
    }

}

void quickSort3(Vector<int> &vec, int l, int r, int crossOverPoint) {
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

    // quickSort3(vec, l, j);
    // quickSort3(vec, j+1, r);
    if(l <= j && j-l+1 <= crossOverPoint) {
        insertionSort(vec, l, j);
    }
    else {
        quickSort3(vec, l, j, crossOverPoint);
    }

    if(j+1 <= r && r-j <= crossOverPoint) {
        insertionSort(vec, j+1, r);
    }
    else {
        quickSort3(vec, j+1, r, crossOverPoint);
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

/*
      N|     quickSort1|     quickSort2|     quickSort3
-------+---------------+---------------+---------------+
     10|        0.00000|        0.00000|        0.00000|
     50|        0.00002|        0.00002|        0.00002|
    100|        0.00005|        0.00005|        0.00006|
    500|        0.00030|        0.00030|        0.00029|
   1000|        0.00040|        0.00040|        0.00041|
   5000|        0.00206|        0.00207|        0.00214|
  10000|        0.00421|        0.00412|        0.00431|
  50000|        0.02167|        0.02112|        0.02180|
*/
