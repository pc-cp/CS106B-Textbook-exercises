
#include <iostream>
#include <string>
#include "direction.h"

using namespace std;

int main(void)
{
    for(Direction dir = NORTH; dir <= WEST; dir++)
        cout << dir << endl;
    return 0;
}
