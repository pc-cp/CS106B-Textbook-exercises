
/*
 * File: BeaconsOfGondor.cpp
 * -------------------------
 * This program illustrates the concept of a linked list by simulating the single linear chain.
 */
#include <iostream>
#include <string>
#include "vector.h"

using namespace std;

struct Tower {
    string name;
    Tower *link;
};

Tower *createBeaconsOfGondor(Vector<string> &names);
Tower *createTower(string name, Tower *link);
void signal(Tower *start);
void free(Tower *start);

int main() {
    Vector<string> names = {"C", "B"};
    Tower *list = createBeaconsOfGondor(names);
    signal(list);
    free(list);
    return 0;
}

Tower *createBeaconsOfGondor(Vector<string> &names) {
    Tower *p, *q = NULL;

    for(string name: names) {
        p = createTower(name, q);
        q = p;
    }
    return q;
}

/*
 * Funciton: createTower
 * Usage: Tower *chain = createTower(name, link);
 * ----------------------------------------------
 * Creates a new Tower structure with the specified components.
 */
Tower *createTower(string name, Tower *link) {
    Tower *tp = new Tower;
    tp->name = name;
    tp->link = link;
    return tp;
}

/* Function: signal
 * Usage: signal(start);
 * ---------------------
 * Generates a signal starting at the current tower and proceeding
 * through the end of the chain.
 */
void signal(Tower *start) {
    for(Tower *tp = start; tp != NULL; tp = tp->link) {
        cout << "Lighting " << tp->name << endl;
    }
}

void free(Tower *start) {
    while(start != NULL) {
        Tower *next = start->link;
        delete start;
        start = next;
    }

    // if(start != NULL) {
    //     free(start->link);
    //     delete start;
    // }
}

