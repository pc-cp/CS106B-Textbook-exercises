
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
    return index == -1 ? "" : bindings.get(index).value;
}

void MyStringMap::put(const string &key, const string &value) {
    int index = findKey(key);
    if(index == -1) {
        KeyValuePair entry;
        entry.key = key;
        index = bindings.size();
        bindings.add(entry);
    }
    bindings[index].value = value;

    // if(index != -1) {
    //     bindings[index] = value;
    // }
    // else {
    //     bindings.add({key, value});
    // }
}

/*
 * Private method: findKey
 * -----------------------
 * Returns the index at which the key appears, or -1 if key is not found.
 */

int MyStringMap::findKey(const string &key) const {
    int index = -1;
    for(int i = 0; i < bindings.size(); ++i) {
        if(bindings.get(i).key == key) {
            index = i;
            break;
        }
    }
    return index;
}
