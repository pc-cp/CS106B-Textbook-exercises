
// E-9-6.cpp

#include <iostream>
#include <iomanip>
#include "grid.h"

using namespace std;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};


// as you know...8250733
//     52    47    56    45    54     5    22    13
//     57    44    53     4    23    14    25     6
//     48    51    46    55    26    21    12    15
//     43    58     3    50    41    24     7    20
//     36    49    42    27    62    11    16    29
//     59     2    37    40    33    28    19     8
//     38    35    32    61    10    63    30    17
//      1    60    39    34    31    18     9    64
// Attempts to solve the Knight's Tour problem on a chessboard.
// The function returns true if a complete tour is found, false otherwise.
bool knightTour(Grid<int> &chessboard, int CurrentRow, int CurrentCol, int &times, int &numCalls) {
    numCalls++;
    // Mark the current cell as visited by setting it to the current step number.
    chessboard[CurrentRow][CurrentCol] = ++times;
    // Uncomment the following line to print the current cell and step number for debugging.
    // cout << CurrentRow << ' ' << CurrentCol << ' ' << times << endl;

    // Check if all cells have been visited.
    bool existNull = false; // Flag to indicate if any cell is unvisited (contains 0).
    for(int i = 0; i < chessboard.numRows(); ++i) {
        for(int j = 0; j < chessboard.numCols(); ++j) {
            if(chessboard[i][j] == 0) {
                existNull = true; // Found an unvisited cell.
                break;
            }
        }
        if(existNull) break; // Break the outer loop if an unvisited cell is found.
    }
    // If no unvisited cells are found, the tour is complete.
    if(!existNull)
        return true;

    // Possible moves a knight can make, represented as changes in row and column.
    // Using this array will significantly increase the search time!
    // int dx[] = {-2, -2, -1, -1, 2, 2, 1, 1}, dy[] = {1, -1, 2, -2, 1, -1, 2, -2};

    // Try all next moves from the current position.
    for(int i = 0; i < 8; ++i) {
        int x = CurrentRow + dx[i], y = CurrentCol + dy[i];
        // Check if the next move is within the board and the cell is unvisited.
        if(x < 0 || x >= chessboard.numRows() || y < 0 || y >= chessboard.numCols() || chessboard[x][y]) {
            continue; // Skip invalid or visited cells.
        }
        // Recursively attempt to solve the tour from the next position.
        if(knightTour(chessboard, x, y, times, numCalls)) {
            return true; // If the tour is successfully completed, return true.
        }
    }

    // Backtrack: undo the current move and try another one.
    times--;
    chessboard[CurrentRow][CurrentCol] = 0;
    return false; // Return false if no complete tour is found from this position.
}



// 513
//     55    64    51    57    41     5    22    13
//     50    58    42     4    23    14    25     6
//     63    52    56    40    26    21    12    15
//     59    49     3    43    38    24     7    20
//     53    60    39    27    45    11    16    29
//     48     2    44   [37]   33    28    19     8
//     61    54    32    46    10    35    30    17
//      1    47    62    34    31    18     9   [36]


// error
void knightTour1(Grid<int> &chessboard, int CurrentRow, int CurrentCol, int &times, int &numCalls) {
    numCalls ++;
    if(CurrentRow < 0 ||
        CurrentRow >= chessboard.numRows() ||
        CurrentCol < 0 ||
        CurrentCol >= chessboard.numCols()) {
        return ;
    }
    if(chessboard[CurrentRow][CurrentCol]) {
        return ;
    }

    chessboard[CurrentRow][CurrentCol] = ++times;
    // int dx[] = {-2, -2, -1, -1, 2, 2, 1, 1}, dy[] = {1, -1, 2, -2, 1, -1, 2, -2};
    for(int i = 0; i < 8; ++i) {
        int x = CurrentRow + dx[i], y = CurrentCol + dy[i];
        knightTour1(chessboard, x, y, times, numCalls);
    }
}


int main() {
    Grid<int> chessboard1(8, 8, 0);
    int times1 = 0, numCalls1 = 0;
    if(knightTour(chessboard1, 7, 0, times1, numCalls1)) {
        cout << "as you know...";
    }
    cout << numCalls1 << endl;
    for(int i = 0; i < chessboard1.numRows(); ++i) {
        for(int j = 0; j < chessboard1.numCols(); ++j) {
            cout << setw(5) << chessboard1[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    Grid<int> chessboard2(8, 8, 0);
    int times2 = 0, numCalls2 = 0;
    knightTour1(chessboard2, 7, 0, times2, numCalls2);
    cout << numCalls2 << endl;
    for(int i = 0; i < chessboard2.numRows(); ++i) {
        for(int j = 0; j < chessboard2.numCols(); ++j) {
            cout << setw(5) << chessboard2[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
