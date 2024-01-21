/*
 * File: combinatorics.h
 * ---------------------
 * Write the files combinatorics.h and combinatorics.cpp
 * for a library that exports the functions permutations and combinations.
 */

#ifndef _combinatorics_h
#define _combinatorics_h

/*
 * Function: combinations
 * Usage: int comb = combinations(n, k);
 * --------------------------------------
 * Returns the mathematical combinations function C(n, k).
 */

int combinations(int n, int k);

/*
 * Function: permutations
 * Usage: int perm = permutations(n, k);
 * --------------------------------------
 * Returns the mathematical combinations function P(n, k).
 */

int permutations(int n, int k);


#endif // _combinatorics_h
