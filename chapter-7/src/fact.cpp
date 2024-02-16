
#include <iostream>

using namespace std;


int fact(int n);

int main(void)
{
    cout << "fact(4) = " << fact(4) << endl;
    return 0;
}



int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n-1);
}
