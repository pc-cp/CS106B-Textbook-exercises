
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

    /* The private section of the class goes here.*/
    /*
     * Notes on the representation
     * ---------------------------
     * This version of the StringMap class stores key-value pairs in a Vector
     */

private:
    /*
     * Type: KeyValuePair
     * ------------------
     * This type combines a key and a value into a single structure.
     */

    struct KeyValuePair{
        std::string key;
        std::string value;
    };

    /* Instance variables */
    Vector<KeyValuePair> bindings;

    /* Private function prototypes */
    int findKey(const std::string &key) const;

};



#endif
