class Solution {
public:
    int fn(int i, int j, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (i < 0 || j < 0) return 1e9; 
        if (i == 0 && j == 0) return grid[0][0];

        if (dp[i][j] != -1) return dp[i][j];

        int up = fn(i - 1, j, m, n, dp, grid); 
        int left = fn(i, j - 1, m, n, dp, grid); 

        return dp[i][j] = grid[i][j] + min(up, left); 
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fn(m - 1, n - 1, m, n, dp, grid); 
    }
};