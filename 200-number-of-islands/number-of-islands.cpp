class Solution {
public:
    int dr[4] = {
        -1,
        0,
        0,
        1,
    };
    int dc[4] = {
        0,
        -1,
        1,
        0,
    };
    void dfs(int i, int j, vector<vector<int>>& vis,
             const vector<vector<char>>& grid) {
        vis[i][j] = 1;

        // need to check in eight direction for adjacent 1 and then call dfs on
        // that i,j

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
                grid[nr][nc] == '1' && !vis[nr][nc]) {
                dfs(nr, nc, vis, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();    // no.of rows
        int m = grid[0].size(); // no. of cols
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};
