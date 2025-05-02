#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return x * x - 4; 
}
double df(double x) {
    return 2 * x; 
}
double newtonRaphson(double x0, double prec, int maxIter) {
    double x1;
    int iter = 0;
    while (iter < maxIter) {
        double f0 = f(x0);
        double df0 = df(x0);
        if (df0 == 0) {
            cout << "Derivative is zero, no solution found!" << endl;
            return x0;
        }
        x1 = x0 - f0 / df0;
        if (fabs(x1 - x0) < prec) {
            cout << "Root found at x = " << x1 << endl;
            return x1;
        }
        x0 = x1;
        iter++;
    }
    cout << "Max iterations reached. Approximate root: " << x1 << endl;
    return x1;
}
int main() {
    double x0 = 1.0;
    double prec = 0.0001; 
    int maxIter = 10; 
    double root = newtonRaphson(x0, prec, maxIter);
    return 0;
}
