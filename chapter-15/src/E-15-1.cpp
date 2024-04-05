
/*
 * File: mystringmap.cpp
 * -------------------
 * This file implements the mystringmap.h interface.
 */
#include <string>
#include "mystringmap.h"

using namespace std;

/*
 * Implementation notes: StringMap constructor and destructor
 * ----------------------------------------------------------
 * All dynamic allocation is handed by the Vector class.
 */

MyStringMap::MyStringMap() { }

MyStringMap::~MyStringMap() { }

/*
 * Implementation notes: put, get
 * ------------------------------
 * These methods use findKey to search for the specified key.
 */

string MyStringMap::get(const string &key) const {
    int index = findKey(key);
    cout << index << endl;
    return ((index == bindings.size() || bindings[index].key != key)) ? "" : bindings[index].value;
}

void MyStringMap::put(const string &key, const string &value) {
    int index = findKey(key);
    if(index != bindings.size() && bindings[index].key < key) {
        index++;
    }

    cout << index << endl;

    if(index == bindings.size() || bindings[index].key != key) {
        KeyValuePair entry;
        bindings.add(entry);
        for(int i = bindings.size()-1; i > index; i--) {
            bindings[i] = bindings[i-1];
        }
        bindings[index].key = key;
    }
    bindings[index].value = value;

}

/*
 * Private method: findKey
 * -----------------------
 * binary search to find key
 * 如果bindings中含有key等于查询的key，则返回对应的下标，
 * 反之返回bindings[index].key > key.
 */

int MyStringMap::findKey(const string &key) const {

    int l = 0, r = bindings.size() - 1;
    while(l < r) {
        int mid = (l + r) >> 1;
        // bingdings[mid].key >= key is true
        if(bindings[mid].key.compare(key) >= 0) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    return l;
}
