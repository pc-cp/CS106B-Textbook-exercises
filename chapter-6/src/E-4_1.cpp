
#include <iostream>
#include <unistd.h> // Include for sleep function on Unix/Linux
#include "PegBoard.h"

const std::string HEADER = "CS106B Programming Abstractions in C++: Ex 6.4";
const std::string DETAIL = "Create yarn-art pattern on a virtual peg board.";
const std::string BANNER = HEADER + DETAIL;

const int N_ACROSS = 50;        // Number of pegs across the top and bottom.
const int N_DOWN = 30;          // Number of pegs down the left and right sides.
const int DELTA = 67;           // Connect first peg to 67th, second peg to 68th/

int main(void)
{
    std::cout << BANNER << std::endl << std::endl;

    PegBoard pb(N_ACROSS, N_DOWN);

    for(int pegDelta = 1; pegDelta < (2 * N_ACROSS + N_DOWN - 2); pegDelta += 2)
    {
        pb.draw(pegDelta, RANDOM);
        sleep(1);
        pb.clear();
    }

    //Conclude with same image from Figure 6-13 of the text.

    pb.draw(DELTA, BLUE);
    waitForClick();     // Prevent auto-teardown of graphic window.

    return 0;
}
