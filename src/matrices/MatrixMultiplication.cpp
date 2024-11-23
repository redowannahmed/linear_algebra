#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat1(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat1[i][j];
        }
    }

    int a, b;
    cin >> a >> b;

    if (n != a) {
        cout << "dimensions don't match" << endl;
        return 0;
    }

    vector<vector<int>> mat2(a, vector<int>(b));

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> mat2[i][j];
        }
    }

    vector<vector<int>> mat3(m, vector<int>(b, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < n; k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j]; 
            }
        }
    }

    cout << endl;
    system("cls");
    cout << "the resultant matrix is: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < b; j++) {
            cout << mat3[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
