
// E-9-5.cpp

#include <iostream>
#include "grid.h"
using namespace std;

/*
 *          0 1 0 0 0
 *          1 0 1 0 0
 *          1 0 1 0 0
 *          1 0 1 0 0
 *          1 1 1 1 1
 */
bool isCols[8] = {0}, isDgs[16] = {0}, isUdgs[16] = {0};
bool Queen(Grid<char> &chessboard, int currentRow, int currentCol);

int main() {
    Grid<char> chessboard(8, 8, '.');

    for(int i = 0; i < chessboard.numRows(); ++i) {
        for(int j = 0; j < chessboard.numCols(); ++j) {
            cout << chessboard[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    if(Queen(chessboard, 0, 0)) {
        for(int i = 0; i < chessboard.numRows(); ++i) {
            for(int j = 0; j < chessboard.numCols(); ++j) {
                cout << chessboard[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}


bool Queen(Grid<char> &chessboard, int currentRow, int currentCol) {
    if(currentRow == chessboard.numRows()) {
        return true;
    }
    if(isCols[currentCol] ||
        isDgs[currentRow - currentCol + chessboard.numRows()] ||
        isUdgs[currentRow + currentCol]) {
        return false;
    }

    chessboard[currentRow][currentCol] = 'Q';
    isCols[currentCol] =
        isDgs[currentRow - currentCol + chessboard.numRows()] =
        isUdgs[currentRow + currentCol] = true;

    for(int i = 0; i < chessboard.numCols(); ++i) {
        if(Queen(chessboard, currentRow+1, i)) {
            return true;
        }
    }

    chessboard[currentRow][currentCol] = '.';
    isCols[currentCol] =
        isDgs[currentRow - currentCol + chessboard.numRows()] =
        isUdgs[currentRow + currentCol] = false;
    return false;
}

