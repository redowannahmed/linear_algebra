#include <bits/stdc++.h>
#include "ToRowEchelon.h"

using namespace std;

vector<double> backSubstitution (vector<vector<double>> &augmentedMatrix)
{
    int n = augmentedMatrix.size ();
    vector<double> solutions (n, 0.00);

    for (int i = n-1; i>=0; i--)
    {
        double sum = augmentedMatrix[i][n];

        for (int j = i+1; j<n; j++)
        {
            sum -= augmentedMatrix[i][j] * solutions[j];
        }

        solutions[i] = sum / augmentedMatrix[i][i];
    }

    return solutions;
}

int main ()
{
    int n;
    cin>>n;
    vector<double> solutions;

    vector<vector<double>> mat (n, vector<double> (n+1));

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n+1; j++)
        {
            cin>>mat[i][j];
        }
    }

    toRowEchelon (mat, n, n+1);

    solutions = backSubstitution (mat);

    cout << endl;

    for (int i = 0; i<n; i++)
    {
        cout << "x" << i+1 << " = " << solutions[i] << endl;
    }

    cout << endl;

    return 0;

}