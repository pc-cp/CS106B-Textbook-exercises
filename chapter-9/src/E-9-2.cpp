
//
// main.cpp
//
// This program implements the function:
//
//    int shortestPathLength(Maze & maze, Point start);
//
// which returns the length of the shortest path in the maze from the
// specified position to any exit.  If there is no solution,
// shortestPathLength returns –1.
//
// --------------------------------------------------------------------------
// Attribution: "Programming Abstractions in C++" by Eric Roberts
// Chapter 9, Exercise 1
// Stanford University, Autumn Quarter 2012
// http://web.stanford.edu/class/archive/cs/cs106b/cs106b.1136/materials/CS106BX-Reader.pdf
//
// The code for adjacentPoint comes from Figure 9-3.
// --------------------------------------------------------------------------
//
// Created by Glenn Streiff on 3/17/16.
// Copyright © 2016 Glenn Streiff. All rights reserved.
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
const std::string MAZEFILE = "maze_E2.txt";
const int NO_PATH = -1;     // No path through maze.

// Function prototypes
bool solveMaze(Maze &maze, Point start, int &times);
Point adjacentPoint(Point start, Direction dir);
bool findSolutionPath(Maze &maze, Point start, Vector<Point> &path, int &times);
// Main program
int main() {

    GWindow gw;
    Maze maze(MAZEFILE, gw);
    maze.drawMaze();
    int times = 0;
    //
    if(solveMaze(maze, maze.getStartPosition(), times)) {
        cout << "Solution found." << endl;
    } else {
        cout << "No solution found." << endl;
    }
    cout << "recursive calls: " << times << endl;
    return 0;
}

bool findSolutionPath(Maze &maze, Point start, Vector<Point> &path, int &times) {
    times++;
    if(maze.isOutside(start)) return true;
    if(maze.isMarked(start)) return true;

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

bool solveMaze(Maze &maze, Point start, int &times) {
    times++;
    if(maze.isOutside(start)) return true;
    if(maze.isMarked(start)) return false;

    maze.markSquare(start);
    for(Direction dir = NORTH; dir <= WEST; dir ++) {
        if(!maze.wallExists(start, dir)) {
            if(solveMaze(maze, adjacentPoint(start, dir), times)) {
                return true;
            }
        }
    }
    // have maze.unmarkSquare(start) : recursive calls: 6317
    // otherwise : recursive calls: 63
    // maze.unmarkSquare(start);
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
