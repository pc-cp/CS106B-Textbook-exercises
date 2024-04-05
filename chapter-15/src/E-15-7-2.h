
/*
 * File: myhashcode.h
 * ----------------
 * The stanford implementation of the HashMap class uses
 * the hash funcion for string, which was developed by
 * Daniel J.Bernstein.
 */

#ifndef _myhashcode_h
#define _myhashcode_h

#include <iostream>
#include "rational.h"

extern const int HASH_SEED;
extern const int HASH_MULTIPLIER;
extern const int HASH_MASK;

int myhashCode(const std::string &str);
int hashCode(const Rational &rat);
#endif
