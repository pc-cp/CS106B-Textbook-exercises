
/* E-11-6.cpp
 * Using the definitions of MAX_JUDGES and scores on page 498 as a starting point
 */

#include <iostream>
#include <iomanip>
#include "simpio.h"
#include "strlib.h"

using namespace std;

const int MAX_JUDGES = 100;
double scores[MAX_JUDGES];

int main() {
    string input;
    int effectiveSize = 0;

    while(true) {
        cout << "Judge #" << effectiveSize + 1 << ":";
        input = getLine();

        if(input == "" || effectiveSize == MAX_JUDGES) {
            break;
        }

        scores[effectiveSize] = stringToReal(input);
        effectiveSize ++;
    }

    int minValueIndex = 0, maxValueIndex = 0;
    for(int i = 0; i < effectiveSize; ++i) {
        if(scores[minValueIndex] > scores[i]) {
            minValueIndex = i;
        }
        if(scores[maxValueIndex] < scores[i]) {
            maxValueIndex = i;
        }
    }

    // cout << minValueIndex << ' ' << maxValueIndex << endl;

    double res = 0;
    for(int i = 0; i < effectiveSize; ++i) {
        if(i != minValueIndex && i != maxValueIndex) {
            res += scores[i];
        }
    }

    if(effectiveSize < 3) {
        error("If the result deletes the minimum and maximum values, the result will be no exist.");
    }

    cout << fixed << setprecision(2) << "The average after eliminating " << scores[minValueIndex] << " and " << scores[maxValueIndex] << " is " << res/(effectiveSize-2) << endl;;

    return 0;
}
