/*
 * File: E-18.cpp
 * --------------
 * illustrate the chain reactions involved in nuclear fission.
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "map.h"
#include "grid.h"
#include "random.h"
using namespace std;

/* Constant */
const int MIN_CYCLES = 1;
const int MAX_CYCLES = 4;
const int TRAPS_ON_A_SIDE = 25;
const int BALLS_ON_EACH_TRAPS = 2;

/* Funciton prototype */
void runSimulation(int &totalTime, double &percentageOfTheSprungTraps, int &maxNumberBallInAir);
void printReport(int totalTime, double percentageOfTheSprungTraps, int maxNumberBallInAir);
void fillGrid(Grid<int> &grid, Vector<int> values);
void fillGrid(Grid<bool> &grid, Vector<bool> values);
/* Main function*/
int main(void)
{
    int totalTime;
    double percentageOfTheSprungTraps;
    int maxNumberBallInAir;
    runSimulation(totalTime, percentageOfTheSprungTraps, maxNumberBallInAir);
    printReport(totalTime, percentageOfTheSprungTraps, maxNumberBallInAir);
    return 0;
}

/* Function: runSimulation
 * Usage: runSimulation();
 * -----------------------
 * Use the time the ping pong ball landed as key
 * and the number of balls corresponding to the landing time as value.
 */

void runSimulation(int &totalTime, double &percentageOfTheSprungTraps, int &maxNumberBallInAir)
{
    totalTime = 0;
    percentageOfTheSprungTraps = 0.0;
    maxNumberBallInAir = 0;

    Grid<int> mousetraps(TRAPS_ON_A_SIDE, TRAPS_ON_A_SIDE);
    Vector<int> pingPongBalls(TRAPS_ON_A_SIDE * TRAPS_ON_A_SIDE, BALLS_ON_EACH_TRAPS);
    fillGrid(mousetraps, pingPongBalls);

    Grid<bool> unSprungTraps(TRAPS_ON_A_SIDE, TRAPS_ON_A_SIDE);
    Vector<bool> unSprungPingPongBalls(TRAPS_ON_A_SIDE * TRAPS_ON_A_SIDE, true);
    fillGrid(unSprungTraps, unSprungPingPongBalls);

    // key: The time of the ball landing
    // value: The number of the balls
    Map<int, int> ballsInAir;
    ballsInAir[1] = 1;

    while(!ballsInAir.isEmpty())
    {
        totalTime ++;

        int currentMaxNumberBallInAir = 0;
        for(int key: ballsInAir)
            currentMaxNumberBallInAir += ballsInAir[key];
        maxNumberBallInAir = max(maxNumberBallInAir, currentMaxNumberBallInAir);

        cout << "current time: " << totalTime;
        cout << ", ballsInAir: " << currentMaxNumberBallInAir << endl;

        if(ballsInAir.containsKey(totalTime))
        {
            for(int i = 0; i < ballsInAir[totalTime]; ++i)
            {
                int row = randomInteger(0, TRAPS_ON_A_SIDE-1);
                int col = randomInteger(0, TRAPS_ON_A_SIDE-1);
                if(unSprungTraps[row][col])
                {
                    for(int j = 0; j < BALLS_ON_EACH_TRAPS; ++j)
                    {
                        int t = randomInteger(MIN_CYCLES, MAX_CYCLES);
                        ballsInAir[totalTime + t] ++;
                    }
                    unSprungTraps[row][col] = false;
                    percentageOfTheSprungTraps += 1;
                    // for(int i = 0; i < unSprungTraps.numRows(); ++i)
                    // {
                    //     for(int j = 0; j < unSprungTraps.numCols(); ++j)
                    //     {
                    //         cout << unSprungTraps[i][j] << ' ';
                    //     }
                    //     cout << endl;
                    // }
                    // cout << endl;
                }
            }
            ballsInAir.remove(totalTime);
        }
    }
    percentageOfTheSprungTraps /= TRAPS_ON_A_SIDE * TRAPS_ON_A_SIDE;
}

/*
 * Function: printReport
 * Usage: void printReport(totalTime, percentageOfTheSprungTraps, maxNumberBallInAir);
 * -----------------------------------------------------------------------------------
 * This function reports the results of the simulation.
 */
void printReport(int totalTime, double percentageOfTheSprungTraps, int maxNumberBallInAir)
{
    cout << "Simulation results given the following constants:"
         << endl;
    cout << fixed << setprecision(2);
    cout << "   TRAPS_ON_A_SIDE:        " << setw(4)
         << TRAPS_ON_A_SIDE << endl;
    cout << "   BALLS_ON_EACH_TRAPS:    " << setw(4)
         << BALLS_ON_EACH_TRAPS << endl;
    cout << "   MIN_CYCLES:       " << setw(4)
         << MIN_CYCLES << endl;
    cout << "   MAX_CYCLES:       " << setw(4)
         << MAX_CYCLES << endl;
    cout << endl;
    cout << "TotalTime:      " << setw(4) << totalTime << endl;
    cout << "PercentageOfTheSprungTraps:  " << setw(7)
         << percentageOfTheSprungTraps << endl;
    cout << "MaxNumberBallInAir:  " << setw(7)
         << maxNumberBallInAir << endl;
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

/*
 * Function: fillGrid
 * Usage: fillGrid(grid, values);
 * ------------------------------
 * function overloading
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
