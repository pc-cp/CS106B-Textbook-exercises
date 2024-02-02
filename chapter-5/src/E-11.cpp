
/*
 * File:E-11.cpp
 * ------------
 * resizes the grid but fills in the data from the original grid
 * by copying elements in the standard row-major order (left-to-right/top-to-bottom).
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
void fillGrid(Grid<int> &grid, Vector<int> values);
void reshape(Grid<int> & grid, int nRows, int nCols);
/* Main function */
int main(void)
{
    Grid<int> myGrid(3, 4);
    Vector<int> values;
    values += 1, 2, 3, 4;
    values += 5, 6, 7, 8;
    values += 9, 10, 11, 12;
    fillGrid(myGrid, values);

    for(int i = 0; i < myGrid.numRows(); ++i)
    {
        for(int j = 0; j < myGrid.numCols(); ++j)
            cout << myGrid[i][j] << ' ';
        cout << endl;
    }
    cout << endl;

    reshape(myGrid, 4, 5);

    for(int i = 0; i < myGrid.numRows(); ++i)
    {
        for(int j = 0; j < myGrid.numCols(); ++j)
            cout << myGrid[i][j] << ' ';
        cout << endl;
    }
    cout << endl;

    return 0;
}

void reshape(Grid<int> & grid, int nRows, int nCols)
{
    Vector<int> data;
    for(int i = 0; i < grid.numRows(); ++i)
    {
        for(int j = 0; j < grid.numCols(); ++j)
        {
            data.add(grid[i][j]);
        }
    }
    Grid<int> ans(nRows, nCols);

    int index = 0;
    bool out_bound = false;
    for(int i = 0; i < nRows; ++i)
    {
        for(int j = 0; j < nCols; ++j)
        {
            if(index >= data.size())
            {
                out_bound = true;
                break;
            }
            ans[i][j] = data[index++];
        }
        if(out_bound) break;
    }

    grid = ans;
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
