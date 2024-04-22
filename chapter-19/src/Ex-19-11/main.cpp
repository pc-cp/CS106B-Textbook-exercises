
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

Expression *changeVariable(Expression *exp, string oldName, string newName);
bool expMatch(Expression *e1, Expression *e2);

void changeVariableRec(Expression * & newExp, Expression *exp, string oldName, string newName);
int main() {
    EvaluationContext context;
    TokenScanner scanner;
    Expression *exp, *newExp;
    scanner.ignoreWhitespace();
    scanner.scanNumbers();
    while(true) {
        exp = NULL;
        newExp = NULL;
        try {
            string line;
            cout << "Ex1: => ";
            getline(cin, line);
            if(line == "quit") break;
            scanner.setInput(line);
            exp = parseExp(scanner);

            cout << "Ex2: => ";
            getline(cin, line);
            if(line == "quit") break;
            scanner.setInput(line);
            newExp = parseExp(scanner);

            if(expMatch(exp, newExp)) {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
            // cout << exp->toString() << endl;
            // int value = exp->eval(context);
            // cout << value << endl;
        } catch (ErrorException &ex) {
            cerr << "Error: " << ex.getMessage() << endl;
        }
        if(exp != NULL) delete exp;
        if(newExp != NULL) delete newExp;
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

Expression *changeVariable(Expression *exp, string oldName, string newName) {
    Expression *newExp = nullptr;
    changeVariableRec(newExp, exp, oldName, newName);
    return newExp;
}

void changeVariableRec(Expression * & newExp, Expression *exp, string oldName, string newName) {

    if(exp->getType() == ExpressionType::COMPOUND) {
        Expression * lhs = nullptr, * rhs = nullptr;
        changeVariableRec(lhs, exp->getLHS(), oldName, newName);
        changeVariableRec(rhs, exp->getRHS(), oldName, newName);

        newExp = new CompoundExp(exp->getOp(), lhs, rhs);
    }
    else if(exp->getType() == ExpressionType::IDENTIFIER) {
        string name = exp->getIdentifierName();
        if(exp->getIdentifierName() == oldName) {
            name = newName;
        }

        newExp = new IdentifierExp(name);
    }
    else {
        newExp = new ConstantExp(exp->getConstantValue());
    }
}


bool expMatch(Expression *e1, Expression *e2) {
    if(e1 == nullptr && e1 == e2) {
        return true;
    }
    if(e1 == nullptr || e2 == nullptr) {
        return false;
    }

    if(e1->getType() != e2->getType()) {
        return false;
    }
    else {
        if(e1->getType() == ExpressionType::COMPOUND) {
            return e1->getOp() == e2->getOp()
                   && (expMatch(e1->getLHS(), e2->getLHS()))
                   && (expMatch(e1->getRHS(), e2->getRHS()));
        }
        else if(e1->getType() == ExpressionType::IDENTIFIER) {
            return e1->getIdentifierName() == e2->getIdentifierName();
        }
        else {
            return e1->getConstantValue() == e2->getConstantValue();
        }
    }
}

