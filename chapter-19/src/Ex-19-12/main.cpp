
void RPN(Expression *exp) {
    Vector<string> ans;
    RPNRec(exp, ans);
    for(auto t : ans) {
        cout << t << ' ';
    }
    cout << endl;
}

void RPNRec(Expression *exp, Vector<string> &ans) {
    if(exp == nullptr) {
        return ;
    }
    else {
        if(exp->getType() == ExpressionType::COMPOUND) {
            RPNRec(exp->getLHS(), ans);
            RPNRec(exp->getRHS(), ans);
            ans.add(exp->getOp());
        }
        else if(exp->getType() == ExpressionType::IDENTIFIER) {
            ans.add(exp->getIdentifierName());
        }
        else {
            stringstream ss;
            ss << exp->getConstantValue();
            ans.add(ss.str());
        }
    }
}
