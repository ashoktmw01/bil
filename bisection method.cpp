#include <iostream>
#include <cmath>
using namespace std;
double func(double x) {
    return x * x - 4;
}
double bisection(double a, double b, double prec) {
    if (func(a) * func(b) >= 0) {
        cout << "Error: f(a) and f(b) must have different signs." << endl;
        return -1;
    }
    double c = a;
    while ((b - a) / 2.0 > prec) {
        c = (a + b) / 2.0;
        if (func(c) == 0.0) {
            break;
        }
        if (func(c) * func(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}
int main() {
    double a = 0.0;
    double b = 3.0;
    double prec = 0.001; 
    double root = bisection(a, b, prec);
    if (root != -1) {
        cout << "The root is approximately: " << root << endl;
    }
    return 0;
}
