// 2D LIS  
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        dp.assign(n, vector<int>(m, -1));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }
        return ans;
    }

    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                matrix[ni][nj] > matrix[i][j]) {
                ans = max(ans, 1 + dfs(ni, nj, matrix));
            }
        }

        return dp[i][j] = ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    cout << sol.longestIncreasingPath(matrix) << endl;

    return 0;
}
