#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return x * x - 4;
}
double secantMethod(double x0, double x1, double prec, int maxIter) {
    double x2;
    int iter = 0;
    while (iter < maxIter) {
        double f0 = f(x0);
        double f1 = f(x1);
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        if (fabs(x2 - x1) < prec) {
            cout << "Root found at x = " << x2 << endl;
            return x2;
        }
        x0 = x1;
        x1 = x2;
        iter++;
    }
    cout << "Max iterations reached. Approximate root: " << x2 << endl;
    return x2;
}
int main() {
    double x0 = 1.0;
    double x1 = 2.0;
    double prec = 0.0001;
    int maxIter = 10;
    double root = secantMethod(x0, x1, prec, maxIter);
    return 0;
}
