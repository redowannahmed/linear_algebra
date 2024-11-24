#include <bits/stdc++.h>
using namespace std;

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