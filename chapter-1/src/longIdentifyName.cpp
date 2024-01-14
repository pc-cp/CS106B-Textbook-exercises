/*
 * File: longIdentifyName.cpp
 * --------------------------
 * This program verifies the following passage
 * Identifiers can be of any length, but C++ compilers 
 * are not required to consider any more than the first 31 
 * characters in determining whether two names are identical.
 */
#include <iostream>
using namespace std;

int main()
{
    int aVeryLongIdentifierNameThatIsUnique1 = 0;
    int aVeryLongIdentifierNameThatIsUnique2 = 1;
    cout << "aVeryLongIdentifierNameThatIsUnique1: " << aVeryLongIdentifierNameThatIsUnique1 << endl;
    cout << "aVeryLongIdentifierNameThatIsUnique2: " << aVeryLongIdentifierNameThatIsUnique2 << endl;
    return 0;
}
