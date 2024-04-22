
/*
 * File: parser.cpp
 * ----------------
 * This file implements the parser.h interface.
 */

#include <iostream>
#include <string>
#include "error.h"
#include "exp.h"
#include "parser.h"
#include "strlib.h"
#include "tokenscanner.h"
using namespace std;

/*
                     T  ---> integer
E  ---> T

                     T  ---> identifier
E  ---> E op E

                     T  ---> ( E )
 */

/*
 * Implementation notes: parseExp
 * ------------------------------
 * This code just reads an expression and then checks for extra tokens.
 */

Expression * parseExp(TokenScanner &scanner) {
    Expression *exp = readE(scanner, 0);
    if(scanner.hasMoreTokens()) {
        error("Unexpected token \"" + scanner.nextToken() + "\"");
    }
    return exp;
}



/*
 *
 *
 * odd = 2 * n  + 1
                        +---------------+
                        |               |
                        |    COMPOUND   |
                        +---------------+
                        |       =       |
                        +---------------+
       +----------------+               |
       |                +---------------+
       |                |               +---------------------+
       |                +---------------+                     |
       |                                                      |
       |                                                      |
       |                                                      |
       |                                                      |
       v                                                      v
+--------------+                                      +---------------+
|              |                                      |               |
|  IDENTIFIER  |                                      |    COMPOUND   |
|              |                                      +---------------+
+--------------+                                      |       +       |
|              |                                      +---------------+
|     odd      |                        +-------------+               |
+--------------+                        |             +---------------+
                                        |             |               +-----------+
                                        |             +---------------+           |
                                        |                                         |
                                        |                                         |
                                        |                                         |
                                        |                                         |
                                        v                                         v
                                +----------------+                        +--------------+
                                |                |                        |              |
                                |    COMPOUND    |                        |   CONSTANT   |
                                +----------------+                        |              |
                                |       *        |                        +--------------+
                                +----------------+                        |              |
                  +-------------+                |                        |     1        |
                  |             +----------------+                        +--------------+
                  |             |                +---------------+
                  |             +----------------+               |
                  |                                              |
                  |                                              |
                  |                                              |
                  v                                              v
           +--------------+                               +--------------+
           |              |                               |              |
           |   CONSTANT   |                               |  IDENTIFIER  |
           |              |                               |              |
           +--------------+                               +--------------+
           |              |                               |              |
           |     2        |                               |      n       |
           +--------------+                               +--------------+
 */


/*
 * Implementation notes: readE
 * Usage: exp = readE(scanner, prec);
 * ----------------------------------
 * The implementation of readE uses precedence to resolve the ambiguity in
 * the grammar. At each level, the parser reads operators and subexpressions
 * until it finds an operator whose precedence is greater than the prevailing
 * one. When a higher-precedence operator is found, readE calls itself
 * recursively to read that subexpression as a unit.
 */
Expression *readE(TokenScanner &scanner, int prec) {
    Expression *exp = readT(scanner);
    string token;
    while(true) {
        token = scanner.nextToken();
        int tprec = precedence(token);
        if(tprec <= prec) break;
        Expression *rhs = readE(scanner, tprec);
        exp = new CompoundExp(token, exp, rhs);
    }
    scanner.saveToken(token);
    return exp;
}


/*
 * Implementation notes: readT
 * ---------------------------
 * This function scans a term, which is either an integer, an identifier,
 * or a parenthesized subexpression.
 */
Expression *readT(TokenScanner &scanner) {
    string token = scanner.nextToken();
    TokenScanner::TokenType type = scanner.getTokenType(token);
    // T  ---> identifier
    if(type == TokenScanner::WORD) return new IdentifierExp(token);
    // T  ---> integer
    if(type == TokenScanner::NUMBER) return new ConstantExp(stringToInteger(token));
    // T  ---> - integer
    if(token == "-") {
        token = scanner.nextToken();
        type = scanner.getTokenType(token);
        if(type == TokenScanner::NUMBER) return new ConstantExp(-1 * stringToInteger(token));
        else error("Illegal term in expression");
    }


    // T  ---> ( E )
    if(token != "(") error("Illegal term in expression");
    Expression *exp = readE(scanner, 0);
    if(scanner.nextToken() != ")") {
        error("Unbalanced parentheses in expression");
    }
    return exp;
}

/*
 * Implementation notes: precedence
 * --------------------------------
 * This function checks the token against each of the defined operators
 * and returns the appropriate precedence value.
 */
int precedence(std::string token) {
    if(token == "=") return 1;
    if(token == "+" || token == "-") return 2;
    if(token == "*" || token == "/" || token == "%") return 3;
    return 0;
}
