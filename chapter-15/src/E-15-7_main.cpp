
#include <iostream>
#include <cassert>
#include "myhashmap.h"
#include "rational.h"
// #include <sstream>
using namespace std;
int main() {
    MyHashMap<int, string> mhp;
    mhp.put(1, "A");
    mhp.put(2, "B");

    assert(mhp.get(2) == "B");
    assert(mhp[2] == "B");
    cout << mhp[2] << endl;

    mhp[2] = "C";
    assert(mhp[2] == "C");
    assert(mhp.containsKey(2));
    assert(!mhp.containsKey(3));
    assert(mhp.size() == 2);
    mhp.clear();
    assert(mhp.size() == 0);
    mhp[2] = "D";
    assert(mhp.size() == 1);
    assert(mhp[2] == "D");

    MyHashMap<int, string> mhp2 = mhp;
    mhp2[1] = "A";
    assert(mhp2.size() == 2);
    assert(mhp.size() == 1);

    assert(!mhp.equals(mhp2));
    mhp[1] = mhp2[1];
    assert(mhp.equals(mhp2));

    cout << mhp.toString() << endl;


    MyHashMap<Rational, string> mhp3;
    Rational r(1, 3);
    mhp3[r] = "1/3";

    cout << mhp3.toString() << endl;
    assert(mhp3[r] == "1/3");
    cout << "Class MyHashMap unit test succeed." << endl;

    return 0;
}
