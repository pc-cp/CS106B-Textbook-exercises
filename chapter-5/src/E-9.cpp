/*
 * File:E-9.cpp
 * ------------
 * performs this check and returns true if the puzzle is a valid solution.
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
bool checkSudokuSolution(Grid<int> & puzzle);
/* Main function */
int main(void)
{
    Grid<int> matrix(9, 9);
    Vector<int> values;
    values += 3, 9, 2, 4, 6, 5, 8, 1, 7;
    values += 7, 4, 1, 8, 9, 3, 6, 2, 5;
    values += 6, 8, 5, 2, 7, 1, 4, 3, 9;
    values += 2, 5, 4, 1, 3, 8, 7, 9, 6;
    values += 8, 3, 9, 6, 2, 7, 1, 5, 4;
    values += 1, 7, 6, 9, 5, 4, 2, 8, 3;
    values += 9, 6, 7, 5, 8, 2, 3, 4, 1;
    values += 4, 2, 3, 7, 1, 9, 5, 6, 8;
    values += 5, 1, 8, 3, 4, 6, 9, 7, 2;
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

    if(checkSudokuSolution(matrix))
        cout << "Above square is a valid solution." << endl;
    else
        cout << "Above square is not a valid solution." << endl;
    return 0;
}


bool checkSudokuSolution(Grid<int> & puzzle)
{

    for(int i = 0; i < puzzle.numRows(); ++i)
    {
        Vector<int> check(10, 0);
        for(int j = 0; j < puzzle.numCols(); ++j)
        {
            if(puzzle[i][j] < 1 || puzzle[i][j] > 9) return false;
            check[puzzle[i][j]]++;
        }
        for(int j = 1; j < check.size(); ++j)
            if(check[j] != 1) return false;
    }

    for(int j = 0; j < puzzle.numCols(); ++j)
    {
        Vector<int> check(10, 0);
        for(int i = 0; i < puzzle.numRows(); ++i)
        {
            if(puzzle[i][j] < 1 || puzzle[i][j] > 9) return false;
            check[puzzle[i][j]]++;
        }
        for(int i = 1; i < check.size(); ++i)
            if(check[i] != 1) return false;
    }

    for(int i = 0; i < puzzle.numRows(); i += 3)
    {
        for(int j = 0; j < puzzle.numCols(); j += 3)
        {
            int i_end = i + 2, j_end = j + 2;
            // cout << i << ' ' << j << ' ' << i_end << ' ' << j_end << ' ' << endl;
            Vector<int> check(10, 0);
            for(int k = i; k <= i_end; ++k)
            {
                for(int z = j; z <= j_end; ++z)
                {
                    if(puzzle[k][z] < 1 || puzzle[k][z] > 9) return false;
                    check[puzzle[k][z]]++;
                }
            }
            for(int k = 1; k < check.size(); ++k)
                if(check[k] != 1) return false;
        }
    }

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
