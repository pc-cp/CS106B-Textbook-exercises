
/*
 * File:E-7.cpp
 * ------------
 * Write a program that uses the sieve of Eratosthenes
 * to generate a list of the primes between 2 and 1000.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
#include "filelib.h"
#include "strlib.h"
#include "vector.h"
#include "map.h"
#include "set.h"
#include "error.h"
#include "grid.h"
using namespace std;

/* Function prototype*/
void fillGrid(Grid<int> &grid, Vector<int> values);
/* Main function */
int main(void)
{
    Grid<int> matrix(3, 3);
    Vector<int> values;
    values += 1, 2, 3;
    values += 4, 5, 6;
    values += 7, 8, 9;
    fillGrid(matrix, values);

    for(int i = 0; i < matrix.numRows(); ++i)
    {
        for(int j = 0; j < matrix.numCols(); ++j)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

/*
 * Function: fillGrid
 * Usage: fillGrid(grid, values);
 * ------------------------------
 * Fill values into the two-dimensional grid
 */
void fillGrid(Grid<int> &grid, Vector<int> values)
{
    for(int i = 0; i < grid.numRows(); ++i)
    {
        for (int j = 0; j < grid.numCols(); ++j)
        {
            grid[i][j] = values[i*grid.numCols()+j];
        }
    }
}



