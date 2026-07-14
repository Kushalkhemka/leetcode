class Solution {
public:
    int fn(int i, int j, int n, vector<vector<int>>& matrix,
           vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= n || j >= n)
            return 1e9;

        if (i == n - 1) {
            return matrix[i][j]; // wind up the stack from this point and keep
                                 // update dp grid in backtracking time with
                                 // child data
        }

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int bottom = fn(i + 1, j, n, matrix, dp);
        int bottomLeft = fn(i + 1, j - 1, n, matrix, dp);
        int bottomRight = fn(i + 1, j + 1, n, matrix, dp);

        return dp[i][j] =
                   min(bottom, min(bottomLeft, bottomRight)) + matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, fn(0, j, n, matrix, dp));
        }

        return mini;
    }
};