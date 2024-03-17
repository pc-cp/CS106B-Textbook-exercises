
/* E-8-14.cpp
 */

#include "simpio.h"
#include "strlib.h"
#include <string>
using namespace std;

const double MINIMUM_INTERVAL = 0.0625;
/* Function prototype */
void draw(double begin, double end);

/* Main function */
int main(void)
{
    draw(0.0, 1.0);
    return 0;
}

void draw(double begin, double end) {
    if(end - begin <= MINIMUM_INTERVAL) {
        ;
    }
    else {
        double middle = (begin + end) / 2;
        printf("%.5f---------%.5f---------%.5f\n", begin, middle, end);
        draw(begin, middle);
        draw(middle, end);
    }
}
