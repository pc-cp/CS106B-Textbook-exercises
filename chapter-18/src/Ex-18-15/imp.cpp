
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const int N = 1e2 + 10;

string name[N] = {"BBN", "CMU", "HARV", "MIT", "NRL", "RAND", "SRI", "STAN", "UCLA", "UTAH"};
int arr[N][N];
int g[N][N];
bool finish[N];
int n, m;

void imp() {

    bool update = true;
    while(update) {
        update = false;

        for(int i = 0; i < n; ++i) {
            if(!finish[i]) {
                for(int j = 0; j < n; ++j) {
                    if(i != j && g[i][j]) {
                        for(int k = 0; k < n; ++k) {
                            if(arr[j][k] != -1) {
                                int oldValue = arr[i][k];
                                if(arr[i][k] == -1 || (arr[i][k] > (arr[j][k] + 1))) {
                                    arr[i][k] = arr[j][k] + 1;
                                }
                                if(arr[i][k] != oldValue) {
                                    update = true;
                                }
                            }
                        }
                    }
                }
                finish[i] = true;
                for(int k = 0; k < n; ++k) {
                    if(arr[i][k] == -1) {
                        finish[i] = false;
                        break;
                    }
                }
            }
        }
    }

}

int main() {
    cin >> n >> m;

    memset(arr, 0xFF, sizeof arr);
    for(int i = 0; i < n; ++i) {
        arr[i][i] = 0;
    }

    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }

    // Interface Message Processor
    imp();

    for(int i = 0; i < n; ++i) {
        cout << setw(5) << name[i] << ": ";
        for(int j = 0; j < n; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

/*
 * input:
 * 10 12
    0 1
    0 3
    1 4
    1 9
    2 3
    2 9
    3 4
    4 5
    5 8
    6 7
    6 9
    7 8
  output:
  BBN: 0 1 2 1 2 3 3 4 4 2
  CMU: 1 0 2 2 1 2 2 3 3 1
 HARV: 2 2 0 1 2 3 2 3 4 1
  MIT: 1 2 1 0 1 2 3 4 3 2
  NRL: 2 1 2 1 0 1 3 4 2 2
 RAND: 3 2 3 2 1 0 3 2 1 3
  SRI: 3 2 2 3 3 3 0 1 2 1
 STAN: 4 3 3 4 3 2 1 0 1 2
 UCLA: 4 3 4 3 2 1 2 1 0 3
 UTAH: 2 1 1 2 2 3 1 2 3 0
 */

