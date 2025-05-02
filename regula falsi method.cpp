#include <iostream>
#include <cmath>
using namespace std;
double func(double x) {
    return x * x - 4;  
}
double regulaFalsi(double a, double b, double tol) {
    if (func(a) * func(b) >= 0) {
        cout << "Error: f(a) and f(b) must have different signs." << endl;
        return -1;
    }
    double c = a;
    while (abs(func(c)) > tol) {
        c = b - (func(b) * (b - a)) / (func(b) - func(a));
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
    double tol = 0.001;
    double root = regulaFalsi(a, b, tol);
    if (root != -1) {
        cout << "The root is approximately: " << root << endl;
    }
    return 0;
}
