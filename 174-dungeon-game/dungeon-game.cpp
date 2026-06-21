class Solution {
public:
    int fn(int i, int j, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& dungeon) {
        if (i > m - 1 || j > n - 1 || i < 0 || j < 0)
            return 1e9; 

        if (i == m - 1 && j == n - 1)
            return max(1, 1 - dungeon[i][j]); 

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = fn(i + 1, j, m, n, dp, dungeon); 
        int right = fn(i, j + 1, m, n, dp, dungeon); 

        int need = min(down, right) - dungeon[i][j]; 
        return dp[i][j] = max(1, need);
    }
  
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size(); 
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fn(0, 0, m, n, dp, dungeon);
    }
};