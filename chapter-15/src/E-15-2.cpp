
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

MyStringMap::MyStringMap() {

    capacity = INITIAL_CAPACITY;
    bindings = new KeyValuePair[capacity];
    length = 0;
}

MyStringMap::~MyStringMap() {
    delete [] bindings;
}

/*
 * Implementation notes: put, get
 * ------------------------------
 * These methods use findKey to search for the specified key.
 */

string MyStringMap::get(const string &key) const {
    if(size() == 0) {
        return "";
    }

    int index = findKey(key);

    return bindings[index].key != key ? "" : bindings[index].value;
}

void MyStringMap::put(const string &key, const string &value) {

    if(size() == capacity) expandCapacity();

    if(size() == 0) {

        bindings[length] = {key, value};
        length++;

    }
    else {

        int index = findKey(key);

        cout << index << endl;

        if(bindings[index].key != key) {

            if(bindings[index].key < key) {
                bindings[size()] = {key, value};
            }
            else {

                for(int i = size(); i > index; i--) {
                    bindings[i] = bindings[i-1];
                }
                bindings[index] = {key, value};
            }
            length++;
        }
        else {
            bindings[index].value = value;
        }
    }

}

int MyStringMap::size() const {
    return length;
}


/*
 * Private method: findKey
 * -----------------------
 * binary search to find key
 * 如果bindings中含有key等于查询的key，则返回对应的下标，
 * 反之返回bindings[index].key > key.
 */

int MyStringMap::findKey(const string &key) const {

    int l = 0, r = size() - 1;
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


void MyStringMap::expandCapacity() {
    KeyValuePair *oldArray = bindings;

    capacity *= 2;
    bindings = new KeyValuePair[capacity];

    for(int i = 0; i < size(); ++i) {
        bindings[i] = oldArray[i];
    }

    delete [] oldArray;

}
