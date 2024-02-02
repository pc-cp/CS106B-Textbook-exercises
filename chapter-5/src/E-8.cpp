
/*
 * File:E-8.cpp
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
bool isMagicSquare(Grid<int> & square);
/* Main function */
int main(void)
{
    Grid<int> matrix(4, 4);
    Vector<int> values;
    values += 16, 3, 2, 13;
    values += 5, 10, 11, 8;
    values += 9, 6, 7, 12;
    values += 4, 15, 14, 1;
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

    if(isMagicSquare(matrix))
        cout << "Above square is a magic square." << endl;
    else
        cout << "Above square is not a magic square." << endl;
    return 0;
}


bool isMagicSquare(Grid<int> & square)
{
    if(square.numRows() != square.numCols()) return false;
    Vector<int> sumRows(square.numRows());
    Vector<int> sumCols(square.numCols());
    Vector<int> sumDiagonals(2);

    for(int i = 0; i < square.numRows(); ++i)
    {
        for(int j = 0; j < square.numCols(); ++j)
            sumRows[i] += square[i][j];

    }

    for(int j = 0; j < square.numCols(); ++j)
    {
        for(int i = 0; i < square.numRows(); ++i)
            sumCols[i] += square[i][j];

    }
    for(int i = 0; i < square.numRows(); ++i)
        sumDiagonals[0] += square[i][i];
    for(int i = 0; i < square.numRows(); ++i)
        sumDiagonals[1] += square[i][square.numRows()-i-1];

    int sum = sumRows[0];
    for(int i = 0; i < sumRows.size(); ++i)
    {
        if(sumRows[i] != sum) return false;
    }

    for(int i = 0; i < sumCols.size(); ++i)
    {
        if(sumCols[i] != sum) return false;
    }

    if(sumDiagonals[0] != sum || sumDiagonals[1] != sum) return false;
    return true;
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



