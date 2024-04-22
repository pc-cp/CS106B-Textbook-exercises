
/*
 * File: Interpreter.cpp
 * ---------------------
 * This program simulates the top level of an expression interpreter. The
 * program reads an expression, evaluates it, and then display the result.
 */

#include <iostream>
#include <string>
#include "error.h"
#include "exp.h"
#include "parser.h"
#include "tokenscanner.h"
#include "set.h"

using namespace std;

void listVariables(Expression *exp);
void listVariablesRec(Expression *exp, Set<string> & identifiers);
int main() {
    EvaluationContext context;
    TokenScanner scanner;
    Expression *exp;
    scanner.ignoreWhitespace();
    scanner.scanNumbers();
    while(true) {
        exp = NULL;
        try {
            string line;
            cout << "=> ";
            getline(cin, line);
            if(line == "quit") break;
            scanner.setInput(line);
            Expression *exp = parseExp(scanner);
            cout << exp->toString() << endl;
            listVariables(exp);
            // int value = exp->eval(context);
            // cout << value << endl;
        } catch (ErrorException &ex) {
            cerr << "Error: " << ex.getMessage() << endl;
        }
        if(exp != NULL) delete exp;
    }
    return 0;
}

void listVariables(Expression *exp) {
    Set<string> identifiers;
    listVariablesRec(exp, identifiers);
    for(auto identifier : identifiers) {
        cout << identifier << endl;
    }
}


void listVariablesRec(Expression *exp, Set<string> & identifiers) {
    if(exp->getType() == ExpressionType::COMPOUND) {
        listVariablesRec(exp->getLHS(), identifiers);
        listVariablesRec(exp->getRHS(), identifiers);
    }
    else if(exp->getType() == ExpressionType::IDENTIFIER) {
        identifiers.add(exp->getIdentifierName());
    }
}
