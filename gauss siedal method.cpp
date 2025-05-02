#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 100;
void inputMatrix(double a[][MAX], double b[], double x[], int &n, double &epsilon, int &maxIterations) {
    cout << "Enter number of variables: ";
    cin >> n;
    cout << "Enter the coefficients of the matrix (row-wise):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    cout << "Enter the constant terms:\n";
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    cout << "Enter initial guess values:\n";
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    cout << "Enter allowed error (epsilon): ";
    cin >> epsilon;
    cout << "Enter maximum number of iterations: ";
    cin >> maxIterations;
}
bool gaussSeidel(double a[][MAX], double b[], double x[], int n, double epsilon, int maxIterations) {
    int iteration = 0;
    bool converge;
    cout << "\nIteration results:\n";
    do {
        converge = true;
        for (int i = 0; i < n; i++) {
            double old = x[i];
            double sum = b[i];

            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j]; 
            }

            x[i] = sum / a[i][i];

            if (fabs(x[i] - old) > epsilon)
                converge = false;
        }
        iteration++;
        cout << "Iteration " << iteration << ": ";
        for (int i = 0; i < n; i++)
            cout << x[i] << " ";
        cout << endl;
    } while (!converge && iteration < maxIterations);
    return converge;
}
void printSolution(double x[], int n) {
    cout << "\nFinal Solution:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << x[i] << endl;
}
int main() {
    double a[MAX][MAX], b[MAX], x[MAX];
    int n, maxIterations;
    double epsilon;
    inputMatrix(a, b, x, n, epsilon, maxIterations);
    bool converged = gaussSeidel(a, b, x, n, epsilon, maxIterations);
    if (converged)
        printSolution(x, n);
    else
        cout << "\nDid not converge within the given number of iterations.\n";
    return 0;
}
