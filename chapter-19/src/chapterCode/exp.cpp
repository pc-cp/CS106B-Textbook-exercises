
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
 * Implementation notes: Expression
 * --------------------------------
 * The Expression class itself implements only those methods that
 * are not designated as pure virtual.
 */
Expression::Expression() {
    /* Empty */
}

Expression::~Expression() {
    /* Empty */
}

int Expression::getConstantValue() {
    error("getConstantValue: Illegal expression type");
    return 0;
}

std::string Expression::getIdentifierName() {
    error("getIdentifierName: Illegal expression type");
    return "";
}

std::string Expression::getOp() {
    error("getOp: Illegal expression type");
    return "";
}

Expression * Expression::getLHS() {
    error("getLHS: Illegal expression type");
    return nullptr;
}

Expression * Expression::getRHS() {
    error("getRHS: Illegal expression type");
    return nullptr;
}

/*
 * Implementation notes: ConstantExp
 * ---------------------------------
 * The ConstantExp subclass represents an integer constant. The eval
 * method simply returns that value.
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
 * Implementation notes: IdentifierExp
 * -----------------------------------
 * The IdentifierExp subclass represents a variable name. The
 * implementation of eval looks up that name in the evaluation context.
 */

IdentifierExp::IdentifierExp(std::string name) {
    this->name = name;
}

int IdentifierExp::eval(EvaluationContext &context) {
    if(!context.isDefined(name)) error(name + " is undefined");
    return context.getValue(name);
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
 * Implementation notes: CompoundExp
 * ---------------------------------
 * The implementation of eval for CompoundExp evaluates the left and right
 * subexpressions recursively and then applies the operator. Assignment is
 * treated as a special case bacause it does not evaluate the left operand.
 */
CompoundExp::CompoundExp(string op, Expression *lhs, Expression *rhs) {
    this->op = op;
    this->lhs = lhs;
    this->rhs = rhs;
}

CompoundExp::~CompoundExp() {
    delete lhs;
    delete rhs;
}

int CompoundExp::eval(EvaluationContext &context) {

    int right = rhs->eval(context);
    if(op == "=") {
        context.setValue(lhs->getIdentifierName(), right);
        return right;
    }
    int left = lhs->eval(context);

    if(op == "+") return left + right;
    if(op == "-") return left - right;
    if(op == "*") return left * right;
    if(op == "/") {
        if(right == 0) error("Division by 0");
        return left / right;
    }
    error("Illegal operator in expression");
    return 0;
}

string CompoundExp::toString() {
    return '(' + lhs->toString() + ' ' + op + ' ' + rhs->toString() + ')';
}

ExpressionType CompoundExp::getType() {
    return COMPOUND;
}

string CompoundExp::getOp() {
    return op;
}

Expression *CompoundExp::getLHS() {
    return lhs;
}

Expression *CompoundExp::getRHS() {
    return rhs;
}



/*
 * Implementation notes: EvaluationContext
 * ---------------------------------------
 * The methods in the EvaluationContext class simply call the appropriate
 * method on the map used to represent the symbol table.
 */

void EvaluationContext::setValue(string var, int value) {
    symbolTable[var] = value;
}

int EvaluationContext::getValue(std::string var) {
    return symbolTable[var];
}

bool EvaluationContext::isDefined(std::string var) {
    return symbolTable.containsKey(var);
}
