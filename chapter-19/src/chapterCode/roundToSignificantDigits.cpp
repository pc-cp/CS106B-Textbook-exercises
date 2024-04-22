
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

double roundToSignificantDigits(double x, int nDigits);


int main() {
    cout << roundToSignificantDigits(3.14159265, 5) << endl;
    return 0;
}


double roundToSignificantDigits(double x, int nDigits) {
    stringstream ss;
    ss << setprecision(nDigits) << x;
    ss >> x;
    return x;
}
