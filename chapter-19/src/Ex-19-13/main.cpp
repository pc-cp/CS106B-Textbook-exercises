
Expression * foldConstants(Expression * exp) {
    Expression *newExp = nullptr;
    foldConstantsRec(newExp, exp);
    return newExp;
}

void foldConstantsRec(Expression * & newExp, Expression * exp) {
    if(exp->getType() == ExpressionType::COMPOUND) {
        Expression * lhs = nullptr, * rhs = nullptr;
        foldConstantsRec(lhs, exp->getLHS());
        foldConstantsRec(rhs, exp->getRHS());
        newExp = new CompoundExp(exp->getOp(), lhs, rhs);

        if(lhs->getType() == ExpressionType::CONSTANT && rhs->getType() == ExpressionType::CONSTANT) {
            EvaluationContext dummy;
            Expression * temp = new ConstantExp(newExp->eval(dummy));
            delete newExp;
            newExp = temp;
        }
        else {
            newExp = new CompoundExp(exp->getOp(), lhs, rhs);
        }
    }
    else if(exp->getType() == ExpressionType::IDENTIFIER) {
        newExp = new IdentifierExp(exp->getIdentifierName());
    }
    else {
        newExp = new ConstantExp(exp->getConstantValue());
    }
}
