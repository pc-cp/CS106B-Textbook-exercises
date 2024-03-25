
#include <iostream>
#include <string>
#include "console.h"
#include "direction.h"
#include "gwindow.h"
#include "maze.h"
#include "point.h"
#include "vector.h"
#include "set.h"
using namespace std;
//     + +-+-+-+-+
//     | |       |
//     + + + + + +
//     | |       |
//     + + + + + +
//     | |       |
//     + + + + + +
//     | |       |
//     + +-+-+-+ +
//     |        S|
//     +-+-+-+-+-+

// Constants
const std::string MAZEFILE = "maze_E2.txt";
const int NO_PATH = -1;     // No path through maze.

// Function prototypes
Point adjacentPoint(Point start, Direction dir);
bool findSolutionPath(Maze &maze, Point start, Vector<Point> &path, int &times);
// Main program
int main() {

    GWindow gw;
    Maze maze(MAZEFILE, gw);
    maze.drawMaze();
    int times = 0;
    Vector<Point> path = {};
    //
    if(findSolutionPath(maze, maze.getStartPosition(), path, times)) {
        cout << "Solution found." << endl;
    } else {
        cout << "No solution found." << endl;
    }
    cout << "recursive calls: " << times << endl;
    cout << path << endl;
    return 0;
}

bool findSolutionPath(Maze &maze, Point start, Vector<Point> &path, int &times) {
    times++;
    if(maze.isOutside(start)) return true;
    if(maze.isMarked(start)) return false;

    maze.markSquare(start);
    path.add(start);

    for(Direction dir = NORTH; dir <= WEST; dir ++) {
        if(!maze.wallExists(start, dir)) {
            if(findSolutionPath(maze, adjacentPoint(start, dir), path, times)) {
                return true;
            }
        }
    }
    path.remove(path.size()-1);
    return false;
}


//
// Function: adjacentPoint
// Usage: Point finish = adjacentPoint(start, dir);
// ------------------------------------------------
// Returns the Point that results from moving one square from start
// in the direction specified by dir.  For example, if pt is the
// point (1, 1), calling adjacentPoint(pt, EAST) returns the
// point (2, 1).  To maintain consistency with the graphics package,
// the y coordinates increase as you move downward on the screen.  Thus,
// moving NORTH decreases the y component, and moving SOUTH increases it.
//

Point adjacentPoint(Point start, Direction dir) {
    switch (dir) {
    case NORTH: return Point(start.getX(), start.getY() - 1);
    case EAST:  return Point(start.getX() + 1, start.getY());
    case SOUTH: return Point(start.getX(), start.getY() + 1);
    case WEST:  return Point(start.getX() - 1, start.getY());
    }
    return start;
}
