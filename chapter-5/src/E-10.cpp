
/*
 * File:E-10.cpp
 * ------------
 * creates a grid of integers storing the number of mines in each neighborhood.
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

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

/* Function prototype*/
void fillGrid(Grid<bool> &grid, Vector<bool> values);
void fixCounts(Grid<bool> & mines, Grid<int> & counts);
/* Main function */
int main(void)
{
    Grid<bool> mines(6, 6);
    Vector<bool> values;
    values += true, false, false, false, false, true;
    values += false, false, false, false, false, true;
    values += true, true, false, true, false, true;
    values += true, false, false, false, false, false;
    values += false, false, true, false, false, false;
    values += false, false, false, false, false, false;
    fillGrid(mines, values);

    // for(int i = 0; i < mines.numRows(); ++i)
    // {
    //     for(int j = 0; j < mines.numCols(); ++j)
    //         cout << mines[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << endl;
    Grid<int> mineCounts;
    fixCounts(mines, mineCounts);

    for(int i = 0; i < mineCounts.numRows(); ++i)
    {
        for(int j = 0; j < mineCounts.numCols(); ++j)
            cout << mineCounts[i][j] << ' ';
        cout << endl;
    }

    return 0;
}

void fixCounts(Grid<bool> & mines, Grid<int> & counts)
{
    counts.resize(mines.numRows(), mines.numCols());
    for(int i = 0; i < mines.numRows(); ++i)
    {
        for(int j = 0; j < mines.numCols(); ++j)
        {
            int sum = mines[i][j] ? 1 : 0;
            for(int k = 0; k < 8; ++k)
            {
                int x = i + dx[k], y = j + dy[k];
                if(x >= 0 && x < mines.numRows() && y >= 0 && y < mines.numCols() && mines[x][y]) sum ++;
            }
            counts[i][j] = sum;
        }
    }
}


/*
 * Function: fillGrid
 * Usage: fillGrid(grid, values);
 * ------------------------------
 * Fill values into the two-dimensional grid
 */
void fillGrid(Grid<bool> &grid, Vector<bool> values)
{
    for(int i = 0; i < grid.numRows(); ++i)
    {
        for (int j = 0; j < grid.numCols(); ++j)
        {
            grid[i][j] = values[i*grid.numCols()+j];
        }
    }
}



