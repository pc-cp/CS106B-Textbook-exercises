
/*
 * File: mystringmap.cpp
 * -------------------
 * This file implements the mystringmap.h interface using a hash table
 * as the underlying representation.
 */
#include <string>
#include "mystringmap.h"
#include "myhashcode.h"

using namespace std;

/*
 * Implementation notes: HashMap constructor and destructor
 * ----------------------------------------------------------
 * The constructor allocates the array of buckets and initializes each
 * bucket to the empty list. The destructor frees the allocated cells.
 */

MyStringMap::MyStringMap() {
    entries = 0;
    nBuckets = INITIAL_BUCKET_COUNT;
    buckets = new Cell* [nBuckets];
    for(int i = 0; i < nBuckets; ++i) {
        buckets[i] = NULL;
    }
}

MyStringMap::~MyStringMap() {
    for(int i = 0; i < nBuckets; ++i) {
        Cell *p = buckets[i];
        Cell *q = NULL;

        while(p) {
            q = p->link;
            delete p;
            p = q;
        }
    }
}

/*
 * Implementation notes: get
 * ------------------------------
 * The get method calls findCell to search the linked list for the
 * matching key. If no key is found, get returns the empty string.
 */

string MyStringMap::get(const string &key) const {
    int bucket = myhashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    return (cp == NULL) ? "" : cp->value;
}

/*
 * Method: put
 * -----------
 * The put method calls findCell to search the linked list for the
 * matching key. If a cell already exist, put simply resets the
 * value field. If no matching key is found, put adds a new cell
 * to the beginning of the list for that chain.
 */
void MyStringMap::put(const string &key, const string &value) {
    int bucket = myhashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    if(cp == NULL) {
        cp = new Cell;
        cp->key = key;
        cp->link = buckets[bucket];
        buckets[bucket] = cp;
        entries ++;
    }
    cp->value = value;

    if(entries*1.0/nBuckets > REHASH_THRESHOLD) {
        rehashing();
    }
}

int MyStringMap::size() const {
    return nBuckets;
}

void MyStringMap::add(const std::string &key, const std::string &value) {
    int bucket = myhashCode(key) % nBuckets;
    Cell *cp = new Cell;
    cp->key = key;
    cp->value = value;

    cp->link = buckets[bucket];
    buckets[bucket] = cp;

}
void MyStringMap::remove(const std::string &key) {
    int bucket = myhashCode(key) % nBuckets;

    Cell *cp = findCell(bucket, key);
    if(cp != NULL) {
        if(cp == buckets[bucket]) {
            buckets[bucket] = cp->link;
        }
        else {
            Cell *pre = buckets[bucket];
            while(pre->link != cp) {
                pre = pre->link;
            }
            pre->link = cp->link;
        }
        delete cp;
    }
}


/*
 * Private method: findCell
 * -----------------------
 * Finds a cell in the chain for the specified bucket that matches key.
 * If a match is found, the return value is a pointer to the cell containing
 * the matching key. If no match is found, findCell return NULL.
 */

MyStringMap::Cell * MyStringMap::findCell(int bucket, const string &key) const {
    Cell *p = buckets[bucket];
    while(p && p->key != key) {
        p = p->link;
    }

    return p;
}


void MyStringMap::rehashing() {
    int oldNBuckets = nBuckets;
    Cell **oldBuckets = buckets;

    entries = 0;
    nBuckets *= 2;
    buckets = new Cell* [nBuckets];

    for(int i = 0; i < nBuckets; ++i) {
        buckets[i] = NULL;
    }

    for(int i = 0; i < oldNBuckets; ++i) {
        Cell *p = oldBuckets[i];
        while(p) {
            this->put(p->key, p->value);
            p = p->link;
        }
    }
}
