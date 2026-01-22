#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> psum;

    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Create prefix sum matrix (n+1) x (m+1)
        psum = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                psum[i][j] = matrix[i-1][j-1]
                           + psum[i-1][j]
                           + psum[i][j-1]
                           - psum[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // convert to 1-based indexing
        row1++; col1++; row2++; col2++;

        return psum[row2][col2]
             - psum[row2][col1 - 1]
             - psum[row1 - 1][col2]
             + psum[row1 - 1][col1 - 1];
    }
};

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    NumMatrix obj(matrix);

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--) {
        int row1, col1, row2, col2;
        cout << "Enter row1 col1 row2 col2: ";
        cin >> row1 >> col1 >> row2 >> col2;

        cout << "Sum = " << obj.sumRegion(row1, col1, row2, col2) << endl;
    }

    return 0;
}
