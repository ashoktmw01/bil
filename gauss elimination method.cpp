#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 100; 
const double EPS = 1e-6;
int main() {
    int n;
    double a[MAX][MAX + 1], x[MAX];
    cout << "Enter the number of variables: ";
    cin >> n;
    cout << "Enter the augmented matrix (coefficients and RHS):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(a[k][i]) > fabs(a[maxRow][i])) {
                maxRow = k;
            }
        }
        for (int j = 0; j <= n; j++) {
            swap(a[i][j], a[maxRow][j]);
        }
        for (int k = i + 1; k < n; k++) {
            double factor = a[k][i] / a[i][i];
            for (int j = i; j <= n; j++) {
                a[k][j] -= factor * a[i][j];
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << "\n";
    }
    return 0;
}
