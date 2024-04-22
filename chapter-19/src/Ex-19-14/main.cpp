
/*
 * Implementation notes: unparse
 * -----------------------------
 * turning the internal representation of an expression back into its text form.
 */
std::string unparse(Expression * exp) {
    return unparseRec(exp, 0);
}

std::string unparseRec(Expression * exp, int prec) {
    string res = "";
    if(exp->getType() == ExpressionType::COMPOUND) {
        int tprec = precedence(exp->getOp());

        res += unparseRec(exp->getLHS(), tprec);
        res += exp->getOp();
        res += unparseRec(exp->getRHS(), tprec);

        if(tprec <= prec) {
            res = "(" + res + ")";
        }
    }
    else if(exp->getType() == ExpressionType::IDENTIFIER) {
        res += exp->getIdentifierName();
    }
    else {
        stringstream ss;
        ss << exp->getConstantValue();
        res += ss.str();
    }
    return res;
}
