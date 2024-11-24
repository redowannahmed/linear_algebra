#include <bits/stdc++.h>
using namespace std;

void printMatrix (vector<vector<double>> &mat, int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (abs(mat[row][col]) < 1e-9) {
                cout << 0 << " ";
            } else {
                cout << mat[row][col] << " ";
            }
        }

        cout << "\n";
    }
}

void toRowEchelon (vector<vector<double>> &mat, int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        // step 1: if the pivot is 0, then swap with one of the rows below (one which doesn't contain a zero in pivot position)
        if (mat[row][row] == 0)
        {
            for (int i = row + 1; i < rows; i++)
            {
                if (mat[i][row] !=0)
                {
                    swap (mat[row], mat[i]);
                    break;
                }
            }
        }

        // step 2: make the pivot 1

        double pivot = mat[row][row];
        if (pivot !=0 )
        {
            for (int col = 0; col < cols; col++)
            {
                mat[row][col] = mat[row][col] / pivot;
            }
        }

        // step 3: get zero below the pivot variable

        for (int i = row + 1; i<rows; i++)
        {
            double factor = mat[i][row]/mat[row][row];

            for (int col = 0; col < cols; col++)
            {
                mat[i][col] -= factor * mat[row][col];
            }
        }
    }
}


void toReducedRowEchelon(vector<vector<double>> &mat, int rows, int cols) {
    toRowEchelon(mat, rows, cols); 

    for (int row = rows - 1; row >= 0; row--) {
        int pivotCol = -1;

        for (int col = 0; col < cols; col++) {
            if (abs(mat[row][col] - 1.0) < 1e-9) { 
                pivotCol = col;
                break;
            }
        }

        if (pivotCol == -1) continue; 

     
        for (int i = row - 1; i >= 0; i--) {
            double factor = mat[i][pivotCol];
            for (int col = 0; col < cols; col++) {
                mat[i][col] -= factor * mat[row][col];
            }
        }
    }
}


int main ()
{
    vector<vector<double>> matrix = {
        {1.00, 2.00, -1.00, -4.00},
        {2.00, 3.00, -1.00, -11.00},
        {-2.00, 0.00, -3.00, 22.00}
    };

    int rows = matrix.size();
    int cols = matrix[0].size();

    toRowEchelon (matrix, rows, cols);

    printMatrix (matrix, rows, cols);

    cout << endl;

    toReducedRowEchelon (matrix, rows, cols);

    printMatrix (matrix, rows, cols);

    cout << endl;

    return 0;
}