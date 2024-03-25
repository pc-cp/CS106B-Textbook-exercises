
// E-9-4.cpp

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

void fillRegion(Grid<bool> & pixels, int row, int col);
int main() {
    Grid<bool> pixels = { {0, 1, 0, 0, 0},
                          {1, 0, 1, 0, 0},
                          {1, 0, 1, 0, 0},
                          {1, 0, 1, 0, 0},
                         {1, 1, 1, 1, 1}};

    for(int i = 0; i < pixels.numRows(); ++i) {
        for(int j = 0; j < pixels.numCols(); ++j) {
            cout << pixels[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    fillRegion(pixels, 0, 2);

    for(int i = 0; i < pixels.numRows(); ++i) {
        for(int j = 0; j < pixels.numCols(); ++j) {
            cout << pixels[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}


// Fills a connected region starting from a specific cell in a grid.
// The function sets the value of each cell in the region to true.
void fillRegion(Grid<bool> &pixels, int row, int col) {
    // Check for out-of-bounds conditions to prevent accessing invalid grid positions.
    if(row < 0 || row >= pixels.numRows() || col < 0 || col >= pixels.numCols()) {
        return; // Exit the function if the current cell is out of bounds.
    }
    else if(pixels[row][col]) {
        return; // Exit the function if the current cell is already true.
    }
    else {
        // Set the current cell to true, marking it as part of the filled region.
        pixels[row][col] = true;

        // Arrays to facilitate exploration in four directions: up, right, down, left.
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

        // Recursively fill adjacent cells that are part of the region.
        // This loop iterates over the four possible directions.
        for(int i = 0; i < 4; ++i) {
            // Recursive call to fill the region starting from the adjacent cell.
            fillRegion(pixels, row + dx[i], col + dy[i]);
        }
    }
}

