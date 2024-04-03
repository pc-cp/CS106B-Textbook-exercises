
#ifndef _pair_h
#define _pair_h

template <typename T1, typename T2>

class Pair {
public:
    Pair();

    Pair(T1 firstValue, T2 secondValue);

    T1 first();

    T2 second();

private:

    T1 firstValue;
    T2 secondValue;

};


template <typename T1, typename T2>
Pair<T1, T2>::Pair() {
    firstValue=T1();
    secondValue=T2();
}

template <typename T1, typename T2>
Pair<T1, T2>::Pair(T1 firstValue, T2 secondValue) {
    this->firstValue = firstValue;
    this->secondValue = secondValue;
}

template <typename T1, typename T2>
T1 Pair<T1, T2>::first() {
    return firstValue;
}

template <typename T1, typename T2>
T2 Pair<T1, T2>::second() {
    return secondValue;
}

#endif // _pair_h
