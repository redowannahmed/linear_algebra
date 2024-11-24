#include <bits/stdc++.h>
#include "ToRowEchelon.h"
using namespace std;

int rankCalculator(vector<vector<double>> &mat, int rows, int cols) {
    toRowEchelon(mat, rows, cols);
    int rank = 0;
    const double EPSILON = 1e-10; 

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (abs(mat[row][col]) > EPSILON) {
                rank++;
                break;
            }
        }
    }
    return rank;
}


int main ()
{
    vector<vector<double>> matrix = {
        {1.00, 2.00, 3.00},
        {2.00, 0.00, 4.00},
        {0.00, 0.00, 0.00}
    };

    cout << rankCalculator (matrix, 3, 3) << endl;

    return 0;
}