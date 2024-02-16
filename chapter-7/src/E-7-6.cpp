/*
 * File: E-7-6.cpp
 * ---------------
 * Write a recursive function (you can call these countFib1 and countFib2 for
 * the two algorithms) that counts the number of function calls made during the evaluation
 * of the corresponding Fibonacci calculation.
 */
#include <iostream>
#include <iomanip>
using namespace std;

/* Function prototype */
int countFib1(int n);
int countFib2(int n);
int fib1(int n, int &cnt);
int fib2(int n, int &cnt);
int additiveSequence(int n, int t0, int t1, int &cnt);

int cnt1, cnt2;
int main(void)
{
    cout << "This program counts the number of calls made by the two" << endl;
    cout << "algorithm used to compute the Fibonacci sequence." << endl << endl;

    cout << right << setw(5) << "n" << setw(3) << " " << setw(4) << "fib1" << setw(3) << " " << setw(4) << "fib2" << endl;
    cout << right << setw(5) << "--" << setw(3) << " " << setw(4) << "----" << setw(3) << " " << setw(4) << "----" << endl;
    for(int n = 0; n <= 12; ++n)
    {
        cout << right << setw(5) << n << setw(3) << " " << setw(4) << countFib1(n) << setw(3) << " " << setw(4) << countFib2(n) << endl;
    }
    return 0;
}

/*
 *
 */
int countFib1(int n)
{
    int cnt = 0;
    fib1(n, cnt);
    return cnt;
}

int countFib2(int n)
{
    int cnt = 0;
    fib2(n, cnt);
    return cnt;
}

/*
 * Function: fib1
 * Usage: int f = fib1(n);
 * ----------------------
 * Returns the nth term in the Fibonacci sequence using the
 * following recursive formulation.
 */
int fib1(int n, int &cnt)
{
    cnt ++ ;
    if(n < 2)
        return n;
    else
        return fib1(n-1, cnt) + fib1(n-2, cnt);
}

int fib2(int n, int &cnt)
{
    cnt++;
    return additiveSequence(n, 0, 1, cnt);
}
/*
 * Function: additiveSequence
 * Usage: int result = additiveSequence(n, t0, t1, cnt);
 * -----------------------------------------------------
 * The key insight you need to discover is that the nth term in any
 * additive sequence is simply the n-1st term in the additive sequence
 * that begins one step further along.
 */
int additiveSequence(int n, int t0, int t1, int &cnt)
{
    cnt++;
    if(n == 0) return t0;
    if(n == 1) return t1;
    return additiveSequence(n-1, t1, t0+t1, cnt);
}
