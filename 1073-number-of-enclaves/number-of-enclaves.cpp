class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid) {
        grid[i][j] = 0;

        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < grid.size() &&
                nc >= 0 && nc < grid[0].size() &&
                grid[nr][nc] == 1) {
                dfs(nr, nc, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        // cover top and bottom boundary
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1) {
                dfs(0, i, grid);
            }

            if (grid[n - 1][i] == 1) {
                dfs(n - 1, i, grid);
            }
        }

        // cover left and right boundary
        for (int i = 1; i < n; i++) {
            if (grid[i][0] == 1) {
                dfs(i, 0, grid);
            }

            if (grid[i][m - 1] == 1) {
                dfs(i, m - 1, grid);
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};