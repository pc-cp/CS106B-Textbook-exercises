
#include <iostream>
#include "set.h"
using namespace std;

void combinationsOfRec(Set<string> picked,
                       const Set<string> &elems,
                       int numToPick) {
    if(picked.size() == numToPick) {
        cout << picked << endl;
    }
    else if(picked.size() + elems.size() < numToPick) {
        return ;
    }
    else {
        string firstElem = elems.first();
        combinationsOfRec(picked+firstElem, elems-firstElem, numToPick);
        combinationsOfRec(picked, elems-firstElem, numToPick);
    }

}
void combinationsOf(const Set<string> &elems,
                    int numToPick) {
    if(elems.size() < numToPick) {
        error("...");
    }
    else {
        combinationsOfRec({}, elems, numToPick);
    }
}


int main(void) {
    Set<string> mySet = {"A", "B", "C", "D"};
    combinationsOf(mySet, 2);
    return 0;
}
