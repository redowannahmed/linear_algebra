#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int m, n;
    cin>>m>>n;

    vector<vector<int>> mat1(m, vector<int> (n));

    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            cin>>mat1[i][j];
        }
    }

    if (m == n)
    {
        for (int i = 0; i<m; i++)
        {
            for (int j = 0; j<=i; j++)
            {
                swap(mat1[i][j], mat1[j][i]);
            }
        }

        cout << "Resultant matrix: " << endl;
        for (int i = 0; i<m; i++)
        {
            for (int j = 0; j<n; j++)
            {
                cout << mat1[i][j] << " ";
            }

            cout << endl;
        }

        return 0;
    }

    else
    {
        vector<vector<int>> mat2 (n, vector<int> (m));

        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                mat2[i][j] = mat1[j][i];
            }
        }

        cout << "resultant matrix: " << endl;

        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m;  j++)
            {
                cout << mat2[i][j] << " ";
            }

            cout << endl;
        }

        cout << endl;

        return 0;
    }
}