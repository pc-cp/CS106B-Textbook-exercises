
#include <iostream>

using namespace std;

double raiseToPower(double x, int n);

double raiseToPower(double x, int n) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return x;
    }
    else {
        if(n % 2 == 1) {
            int first = n/2;
            // int second = n/2+1;
            double firstPower = raiseToPower(x, first);
            return firstPower * firstPower * x;
        }
        else {
            int first = n/2;
            double firstPower = raiseToPower(x, first);
            return firstPower * firstPower;
        }
    }
}

int main() {
    double x;
    int n;

    while(true) {
        cin >> x >> n;
        if(x == 0) {
            break;
        }
        cout << raiseToPower(x, n) << endl;
    }
    return 0;
}
