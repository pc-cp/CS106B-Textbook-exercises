
/* Implementation of toString and the << operator */
string Rational::toString() const
{
    if(den == 1)
        return integerToString(num);
    else
        return integerToString(num) + "/" + integerToString(den);
}
