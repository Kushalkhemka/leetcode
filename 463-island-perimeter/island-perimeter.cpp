class Solution {
public:
    int ans = 0;

    bool isValid(int nr, int nc, int m, int n) {
        return nr >= 0 && nr < m && nc >= 0 && nc < n; 
    }

    void dfs(int i, int j, vector<vector<int>>& vis,
             const vector<vector<int>>& grid, int m, int n) { 
        vis[i][j] = 1;

        // need to check in four directions only: up, left, right, down
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (!isValid(nr, nc, m, n) || grid[nr][nc] == 0) {
                ans++;
            } else if (!vis[nr][nc]) {
                dfs(nr, nc, vis, grid, m, n); 
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, visited, grid, m, n); 
                    return ans;
                }
            }
        }

        return 0;
    }
};