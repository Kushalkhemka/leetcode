class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans += 4;

                    if (i > 0 && grid[i - 1][j] == 1) ans -= 2; // shared edge with upper land
                    if (j > 0 && grid[i][j - 1] == 1) ans -= 2; // shared edge with left land
                }
            }
        }

        return ans;
    }
};