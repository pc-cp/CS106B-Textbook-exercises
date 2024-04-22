
/*
 * File: exp.cpp
 * -------------
 * This file implements the exp.h interface.
 */

#include <string>
#include "error.h"
#include "exp.h"
#include "strlib.h"

using namespace std;

/*
 * Expression
 */
Expression::Expression() {
    /* Empty */
}

Expression::~Expression() {
    /* Empty */
}

int Expression::getConstantValue() {
    error("you should override this function instead call by base class");
    return -1;
}

std::string getIdentifierName() {
    error("you should override this function instead call by base class");
    return "";
}

std::string getOp() {
    error("you should override this function instead call by base class");
    return "";
}

Expression *getLHS() {
    error("you should override this function instead call by base class");
    return nullptr;
}

Expression *getRHS() {
    error("you should override this function instead call by base class");
    return nullptr;
}

/*
 * ConstantExp
 */
ConstantExp::ConstantExp(int value) {
    this->value = value;
}

int ConstantExp::eval(EvaluationContext &context) {
    return getConstantValue();
}

int ConstantExp::getConstantValue() {
    return this->value;
}

ExpressionType ConstantExp::getType() {
    return CONSTANT;
}

std::string ConstantExp::toString() {
    return integerToString(getConstantValue());
}

/*
 * IdentifierExp
 */

IdentifierExp::IdentifierExp(std::string name) {
    this->name = name;
}

int IdentifierExp::eval(EvaluationContext &context) {
    context.getValue(getIdentifierName());
}

std::string IdentifierExp::getIdentifierName() {
    return this->name;
}

ExpressionType IdentifierExp::getType() {
    return IDENTIFIER;
}

std::string IdentifierExp::toString() {
    return getIdentifierName();
}

/*
 * CompoundExp
 */
CompoundExp::CompoundExp(string op, Expression *lhs, Expression *rhs) {
    this->op = op;
    this->lhs = lhs;
    this->rhs = rhs;
}

int CompoundExp::eval(EvaluationContext &context) {

    ExpressionType let = this->lhs->getType();
    ExpressionType ret = this->rhs->getType();

    int lvalue, rvalue;

    switch (let) {
    case IDENTIFIER:
    case CONSTANT:
    case COMPOUND:
        lvalue = this->lhs->eval(context);
        break;
    default:
        error("Unidentified data types.");
    }

    switch (ret) {
    case IDENTIFIER:
    case CONSTANT:
    case COMPOUND:
        rvalue = this->rhs->eval(context);
        break;
    default:
        error("Unidentified data types.");
    }

    switch(op[0]) {
    case '+':
        return lvalue + rvalue;
    case '-':
        return lvalue - rvalue;
    case '*':
        return lvalue * rvalue;
    case '/':
        return lvalue / rvalue;
    case '=':
        setValue(lhs->getIdentifierName(), rvalue);
        return rvalue;
    default :
        error("Undefined operator.");
    }

}

/*
 * EvaluationContext
 */

void EvaluationContext::setValue(string var, int value) {
    symbolTable[var] = value;
}

int EvaluationContext::getValue(std::string var) {
    if(!isDefined(var)) {
        error("The identifier is undefined before use.");
    }
    return symbolTable[var] = value;
}

bool EvaluationContext::isDefined(std::string var) {
    return symbolTable.containsKey(var);
}
