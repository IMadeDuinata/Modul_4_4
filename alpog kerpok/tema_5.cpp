#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double A[3][3] = {
        { 2, 1, -1},
        {-3, -1, 2},
        {-2, 1, 2}
    };
    double b[3] = { 8, -11, -3 };
    int n = 3;

    for(int i = 0; i < n; i++){
        if(A[i][i] == 0){
            cout << "Pivot nol! Tukar baris diperlukan.\n";
            return 0;
        }

        for(int j = i + 1; j < n; j++){
            double factor = A[j][i] / A[i][i];
            for(int k = i; k < n; k++){
                A[j][k] -= factor * A[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    double x[3];
    for(int i = n-1; i >= 0; i--){
        double sum = b[i];
        for(int j = i+1; j < n; j++){
            sum -= A[i][j] * x[j];
        }
        x[i] = sum / A[i][i];
    }

    cout << "Hasil:\n";
    cout << "x = " << x[0] << endl;
    cout << "y = " << x[1] << endl;
    cout << "z = " << x[2] << endl;

    return 0;
}
