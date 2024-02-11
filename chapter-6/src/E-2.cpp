
/*
 * chapter-6
 * File: E-2.cpp
 */

#include <iostream>
#include <string>
#include "card.h"

using namespace std;

int main(void)
{
    for(Suit suit = CLUBS; suit <= SPADES; suit++)
    {
        for(int rank = ACE; rank <= KING; rank++)
        {
            cout << " " << Card(rank, suit);
        }
        cout << endl;
    }
    return 0;
}
