//

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

// Constants
const std::string MAZEFILE = "maze.txt";
const int NO_PATH = -1;     // No path through maze.

// Function prototypes
bool solveMaze(Maze &maze, Point start);
int shortestPathLengthRec(Maze & maze, Point start);

Point adjacentPoint(Point start, Direction dir);

// Main program

int main() {

    GWindow gw;
    Maze maze(MAZEFILE, gw);
    maze.drawMaze();
    Vector<Point> path;

    int distance = shortestPathLengthRec(maze, maze.getStartPosition());
    if(distance != -1) {
        cout << distance << endl;
    }
    else {
        cout << "No solution exists." << endl;
    }
    return 0;
}

int shortestPathLengthRec(Maze & maze, Point start) {
    if(maze.isOutside(start)) return 0;
    if(maze.isMarked(start)) return -1;

    maze.markSquare(start);

    int shortDistance = -1;
    for(Direction dir = NORTH; dir <= WEST; dir++) {
        if(!maze.wallExists(start, dir)) {
            int dist = shortestPathLengthRec(maze, adjacentPoint(start, dir));
            if(dist != -1 && (shortDistance == -1 || dist < shortDistance)) {
                shortDistance = dist;
            }
        }
    }
    maze.unmarkSquare(start);
    if(shortDistance != -1) {
        return shortDistance+1;
    }
    return shortDistance;
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
