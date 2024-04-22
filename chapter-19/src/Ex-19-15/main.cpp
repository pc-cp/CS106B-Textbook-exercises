/*
 * File: Ex-19-15.cpp
 * ---------------------
 * reads expressions from infile and writes to outfile a sequence of
 * instructions for the stack machine that have the same effect as evaluating each
 * of the expressions in the input file and displaying their result.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "error.h"
#include "exp.h"
#include "parser.h"
#include "tokenscanner.h"
#include "set.h"
#include "vector.h"

using namespace std;
void compile(istream & infile, ostream & outfile);
int compileRec(Expression *exp, ostream &outfile, EvaluationContext& context);

int main() {
    ifstream infile;
    ofstream outfile;

    infile.open("expressions.txt");
    outfile.open("instructions.txt");
    if(infile.fail() || outfile.fail()) {
        error("open failed.");
    }

    compile(infile, outfile);
    return 0;
}

int compileRec(Expression *exp, ostream &outfile, EvaluationContext& context) {
    if(exp->getType() == ExpressionType::COMPOUND) {
        int right = compileRec(exp->getRHS(), outfile, context);

        if(exp->getOp() == "=") {
            string name = exp->getLHS()->getIdentifierName();
            context.setValue(name, right);
            outfile << "STORE " << name << endl;
            return right;
        }
        int left = compileRec(exp->getLHS(), outfile, context);
        if(exp->getOp() == "+") {
            outfile << "ADD" << endl;
            return left + right;
        }
        if(exp->getOp() == "-") {
            outfile << "SUB" << endl;
            return left - right;
        }
        if(exp->getOp() == "*") {
            outfile << "MUL" << endl;
            return left * right;
        }
        if(exp->getOp() == "/") {
            if(right == 0) error("Division by 0");
            outfile << "DIV" << endl;
            return left / right;
        }
    }
    else if(exp->getType() == ExpressionType::IDENTIFIER) {
        string name = exp->getIdentifierName();
        if(!context.isDefined(name)) {
            error(name + " is undefined");
        }
        outfile << "LOAD " << name << endl;
        return context.getValue(name);
    }

    int value = exp->getConstantValue();
    outfile << "LOAD #" << value << endl;
    return value;

}

void compile(istream & infile, ostream & outfile) {
    EvaluationContext context;
    TokenScanner scanner;
    Expression *exp;
    string line;
    scanner.ignoreWhitespace();
    scanner.scanNumbers();
    while(getline(infile, line)) {
        exp = NULL;
        try {
            scanner.setInput(line);
            exp = parseExp(scanner);
            int value = compileRec(exp, outfile, context);
            outfile << "DISPLAY " << "(" << value << ")"<< endl;

        } catch (ErrorException &ex) {
            cerr << "Error: " << ex.getMessage() << endl;
        }
        if(exp != NULL) delete exp;

    }
}
