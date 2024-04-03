
#include <iostream>
#include <cassert>
#include "myvector.h"
using namespace std;

int main() {

    MyVector<int> vec1, vec2(10, 1), vec3(9);

    // for(int i = 0; i < vec2.size(); ++i) {
    //     cout << vec2.get(i) << ' ';
    // }
    // cout << endl;

    assert(vec1.size() == 0);
    assert(vec1.isEmpty());
    assert(!vec3.isEmpty());

    vec2.clear();

    // for(int i = 0; i < vec2.size(); ++i) {
    //     cout << vec2.get(i) << ' ';
    // }
    // cout << endl;

    vec1 = vec3;
    // for(int i = 0; i < vec1.size(); ++i) {
    //     cout << vec1.get(i) << ' ';
    // }
    // cout << endl;

    vec2 = MyVector(2, 11);
    // for(int i = 0; i < vec2.size(); ++i) {
    //     cout << vec2.get(i) << ' ';
    // }
    // cout << endl;

    vec1.set(2, 111);
    // for(int i = 0; i < vec1.size(); ++i) {
    //     cout << vec1[i] << ' ';
    // }
    // cout << endl;

    assert(vec1.get(2) == 111);

    vec1.remove(2);
    assert(vec1.size() == 8);
    assert(vec1.get(2) == 0);

    vec1.add(99);
    assert(vec1.size() == 9);
    assert(vec1.get(8) == 99);
    assert(vec1[8] == 99);
    assert(vec1[2] == 0);
    vec1[8] = 999;
    assert(vec1[8] == 999);
    cout << "class MyVector is pass unit test successfully." << endl;
    return 0;
}
