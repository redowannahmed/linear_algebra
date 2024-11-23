#include <bits/stdc++.h>
using namespace std;



int main ()
{
    int m, n;
    cin>>m>>n;

    vector<vector<int>> mat1 (m, vector<int> (n));

    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            cin>>mat1[i][j];
        }
    }

    cout << "enter the scalar multiplicand: ";

    int c;
    cin>> c;

    cout << endl;

    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            mat1[i][j] = c* mat1[i][j];
        }
    }



    cout << "the resultant matrix now is: " << endl;

    system("cls");
    
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