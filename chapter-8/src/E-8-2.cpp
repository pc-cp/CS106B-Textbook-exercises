
/*
 * File: E-8-2.cpp
 * ---------------
 * Rewrite the Towers of Hanoi program so that the moveTower function checks whether n is 0 instead.
 */
#include <iostream>
#include "simpio.h"
using namespace std;

/* Function prototype */
void moveTower(int n, char start, char finish, char tmp);
void moveSingleDisk(char start, char finish);
int countHanoiMoves(int n);

int main(void)
{

    int n = getInteger("Enter number of disks: ");
    moveTower(n, 'A', 'B', 'C');
    cout << "the number of moves: ";
    cout << countHanoiMoves(n) << endl;
    return 0;
}

/*
 * Function: moveTower
 * Usage: moveTower(n, start, finish, tmp);
 * ----------------------------------------
 * Moves a tower of size n from the start spire to the finish
 * spire using the tmp spire as the temporary repository.
 */
void moveTower(int n, char start, char finish, char tmp)
{
    if(n == 0)
        return ;
    // cout << "the " << n << "th have been move from " << start << " to " << finish << endl;
    else
    {
        // Move the entire stack consisting of the top n-1 disks from spire A to spire C.
        moveTower(n-1, start, tmp, finish);
        // Move the bottom disk from spire A to spire B.
        moveSingleDisk(start, finish);
        // cout << "the " << n << "th have been move from " << start << " to " << finish << endl;
        // Move the stack of n-1 disks from spire C to spire B.
        moveTower(n-1, tmp, finish, start);
    }
}

/*
 * Function: moveSingleDisk
 * Usage: moveSingleDisk(start, finish);
 * -------------------------------------
 * Executes the transfer of a single disk from the start spire to the
 * finish spire. In this implementation, the move is simply displayed
 * on the consloe; in a graphical implementation, the code would update
 * the graphics window to show the new arrangement.
 */
void moveSingleDisk(char start, char finish)
{
    cout << start << " -> " << finish << endl;
}


int countHanoiMoves(int n) {
    if(n == 1)
        return 1;
    else {
        int times = 0;
        times += countHanoiMoves(n-1);
        times ++;
        times += countHanoiMoves(n-1);
        return times;
    }
}
