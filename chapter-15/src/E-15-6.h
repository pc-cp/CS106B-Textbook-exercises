
/*
 * File: mystringmap.h
 * -----------------
 * This interface exports a simplified version of the Map class in which
 * the keys and values are always strings.
 */

#ifndef _mystringmap_h
#define _mystringmap_h

#include <string>
#include "vector.h"

class MyStringMap {
public:
    /*
     * Constructor: MyStringMap
     * Usage: MyStringMap map;
     * ---------------------
     * Initializes a new empty map that uses strings as both keys and values.
     */

    MyStringMap();

    /*
     * Destructor: ~MyStringMap
     * ----------------------
     * Frees any heap storage associated with this map.
     */
    ~MyStringMap();

    /*
     * Method: get
     * Usage: string value = map.get(key);
     * -----------------------------------
     * Returns the value for key or the empty string, if key is unbound.
     */

    std::string get(const std::string &key) const;

    /*
     * Method: put
     * Usage: map.put(key, value);
     * ---------------------------
     * Associated key with value in this map.
     */

    void put(const std::string &key, const std::string &value);

    int size() const;

    void add(const std::string &key, const std::string &value);
    void remove(const std::string &key);
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
        std::string key;
        std::string value;
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
    Cell *findCell(int bucket, const std::string &key) const;

    void rehashing();

    /* Make copying illegal */
    MyStringMap(const MyStringMap &src) {}
    MyStringMap &operator= (const MyStringMap &src) {return *this;}

};



#endif
