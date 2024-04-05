
#ifndef _myhashmap_h
#define _myhashmap_h

#include <string>
#include <sstream>
#include "myhashcode.h"
#include "hashcode.h"

template <typename KeyType, typename ValueType>
class MyHashMap {
public:


    MyHashMap();

    ~MyHashMap();

    ValueType get(const KeyType &key) const;

    void put(const KeyType &key, const ValueType &value);

    int size() const;

    // Removes all entries from this map.
    void clear();

    // Returns true if there is an entry for key in this map.
    bool containsKey(const KeyType &key) const;

    // Returns true if the two maps contain the same entries.
    bool equals(const MyHashMap<KeyType, ValueType> &src);

    // Returns a printable string representation of this map.
    std::string toString();


    /* deepCopy */
    MyHashMap(const MyHashMap<KeyType, ValueType> &src);
    MyHashMap<KeyType, ValueType> &operator= (const MyHashMap<KeyType, ValueType> &src);

    ValueType & operator[] (const KeyType &key);

    /* The private section of the class goes here.*/
    /*
     * Notes on the representation
     * ---------------------------
     * This version of the StringMap class uses a hash table that keeps the
     * key-value pairs in an array of buckets, each of which is a linked list
     * of keys that hash to that bucket.
     */

private:
    /* Type definition for cells in the bucket chain. */

    struct Cell {
        KeyType key;
        ValueType value;
        Cell *link;
    };

    /* load factor*/
    constexpr static const double REHASH_THRESHOLD = 0.7;
    /* Constant definition*/
    static const int INITIAL_BUCKET_COUNT = 3;

    /* Instance variables */
    Cell **buckets;         // Dynamic array of pointers to cells
    int nBuckets;           // The number of buckets in the array
    int entries;

    /* Private methods */
    Cell * findCell(int bucket, const KeyType &key) const;

    void rehashing();
    void deepCopy(const MyHashMap<KeyType, ValueType> &src);
};

template <typename KeyType, typename ValueType>
MyHashMap<KeyType, ValueType>::MyHashMap() {
    entries = 0;
    nBuckets = INITIAL_BUCKET_COUNT;
    buckets = new Cell* [nBuckets];
    for(int i = 0; i < nBuckets; ++i) {
        buckets[i] = NULL;
    }
}

template <typename KeyType, typename ValueType>
MyHashMap<KeyType, ValueType>::~MyHashMap() {
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

template <typename KeyType, typename ValueType>
ValueType MyHashMap<KeyType, ValueType>::get(const KeyType &key) const {
    // int bucket = myhashCode(key) % nBuckets;
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    return (cp == NULL) ? "" : cp->value;
}

template <typename KeyType, typename ValueType>
void MyHashMap<KeyType, ValueType>::put(const KeyType &key, const ValueType &value) {
    // int bucket = myhashCode(key) % nBuckets;
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    if(cp == NULL) {
        cp = new Cell;
        cp->key = key;
        cp->link = buckets[bucket];
        buckets[bucket] = cp;
        entries ++;
    }
    cp->value = value;

    if(size()*1.0/nBuckets > REHASH_THRESHOLD) {
        rehashing();
    }
}

template <typename KeyType, typename ValueType>
int MyHashMap<KeyType, ValueType>::size() const {
    return entries;
}

template <typename KeyType, typename ValueType>
void MyHashMap<KeyType, ValueType>::clear() {
    entries = 0;
    for(int i = 0; i < nBuckets; ++i) {
        Cell *cp = buckets[i];
        Cell *q = NULL;
        while(cp) {
            q = cp->link;
            delete cp;
            cp = q;
        }
        buckets[i] = NULL; // miss will lead error.
    }
}

template <typename KeyType, typename ValueType>
bool MyHashMap<KeyType, ValueType>::containsKey(const KeyType &key) const {
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    return cp != NULL;
}

template <typename KeyType, typename ValueType>
bool MyHashMap<KeyType, ValueType>::equals(const MyHashMap<KeyType, ValueType> &other) {
    if(size() != other.size() || nBuckets != other.nBuckets) {
        return false;
    }

    Cell *pThis, *pOther;
    for(int i = 0; i < nBuckets; ++i) {
        pThis = buckets[i], pOther = other.buckets[i];
        while(pThis || pOther) {
            if(!pThis || !pOther) return false;
            if(pThis->key != pOther->key || pThis->value != pOther->value) return false;
            pThis = pThis->link;
            pOther = pOther->link;
        }
    }
    return true;
}

template <typename KeyType, typename ValueType>
std::string MyHashMap<KeyType, ValueType>::toString() {
    std::ostringstream oss;

    Cell *cp = NULL;
    for(int i = 0; i < nBuckets; ++i) {
        cp = buckets[i];
        while(cp) {
            oss << "{" << cp->key << "," << cp->value << "}";
            cp = cp->link;
        }
    }
    return oss.str();
}

template <typename KeyType, typename ValueType>
typename MyHashMap<KeyType, ValueType>::Cell * MyHashMap<KeyType, ValueType>::findCell(int bucket, const KeyType &key) const {
    Cell *p = buckets[bucket];
    while(p && p->key != key) {
        p = p->link;
    }

    return p;
}


template <typename KeyType, typename ValueType>
void MyHashMap<KeyType, ValueType>::rehashing() {
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

template <typename KeyType, typename ValueType>
MyHashMap<KeyType, ValueType>::MyHashMap(const MyHashMap<KeyType, ValueType> &src) {
    deepCopy(src);
}

template <typename KeyType, typename ValueType>
MyHashMap<KeyType, ValueType>& MyHashMap<KeyType, ValueType>::operator =(const MyHashMap<KeyType, ValueType> &src) {
    if(this != &src) {
        // free old heap storage
        clear();
        delete [] buckets;
        nBuckets = 0;

        // deepCopying
        deepCopy(src);
    }
}

template <typename KeyType, typename ValueType>
void MyHashMap<KeyType, ValueType>::deepCopy(const MyHashMap<KeyType, ValueType> &src) {
    nBuckets = src.nBuckets;
    entries = src.entries;
    buckets = new Cell* [nBuckets];
    for(int i = 0; i < nBuckets; ++i) {
        buckets[i] = NULL;
    }

    for(int i = 0; i < nBuckets; ++i) {
        Cell *p = src.buckets[i];
        Cell *q = buckets[i];
        while(p) {
            Cell *tmp = new Cell;
            tmp->key = p->key;
            tmp->value = p->value;
            tmp->link = NULL;

            if(buckets[i] == NULL) {
                buckets[i] = tmp;
            }
            else {
                q->link = tmp;
            }

            q = tmp;
            p = p->link;
        }
    }

}

template <typename KeyType, typename ValueType>
ValueType & MyHashMap<KeyType, ValueType>::operator[] (const KeyType &key) {
    // int bucket = myhashCode(key) % nBuckets;
    int bucket = hashCode(key) % nBuckets;

    Cell *cp = findCell(bucket, key);
    if(cp == NULL) {
        cp = new Cell;
        cp->key = key;
        // cp->value = ValueType ();
        cp->link = buckets[bucket];
        buckets[bucket] = cp;
        entries ++;
    }
    return cp->value;
}

#endif // _myhashmap_h
