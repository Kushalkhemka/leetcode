class Solution {
public:
    int fn(int i, int j, int m, int n, vector<vector<int>>& dp,
           vector<vector<int>>& triangle) {
        if (i < 0 || j < 0 || j > n - 1 || i > m - 1)
            return 1e9;

        if (i == 0)
            return triangle[0][0];

        if (dp[i][j] != -1)
            return dp[i][j];

        int fs = fn(i - 1, j, m, n - 1, dp, triangle);
        int ss = fn(i - 1, j - 1, m, n - 1, dp, triangle);

        return dp[i][j] = triangle[i][j] + min(fs, ss);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 1e9; // changed: store minimum among all bottom cells

        for (int j = 0; j < n; j++) { 
            ans = min(ans, fn(m - 1, j, m, n, dp, triangle)); 
        }

        return ans; 
    }
};