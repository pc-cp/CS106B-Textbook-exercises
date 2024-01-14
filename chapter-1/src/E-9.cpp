/*
 * File: E-9.cpp
 * -------------
 * display the prime factorization of a number n
 */
#include <iostream>
using namespace std;

/* Functione prototypes */
void primeFactorization(int n);

/* Functione prototypes */
bool isPrime(int n);

int n;
/* Main program */
int main(void)
{
    cout << "This program factors a number." << endl
         << "Enter number to be factored: ";
    cin >> n;
    primeFactorization(n);
    return 0;
}

void primeFactorization(int n)
{
    if(isPrime(n))
    {
        cout << n << " is prime" << endl;
        return ;
    }
    do
    {
        for(int i = 2; i <= n; ++i)
        {
            if(isPrime(i) && n % i == 0)
            {
                cout << i << ' ';
                n /= i;
                if(n != 1)
                    cout << 'X' << ' ';
                break;
            }
        }
        
    }while(n != 1);
    cout << endl;
}

bool isPrime(int n)
{
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0)
            return false;
    return true;
}
