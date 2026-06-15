class Solution {
public:

    void dfs(int i, int j,
              vector<vector<int>>& grid, int &area) {
        grid[i][j] = 0; //fully processed no vis array needed
        area++;

        // need to check in eight direction for adjacent 1 and then call dfs on
        // that i,j
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
                grid[nr][nc] == 1) {
                dfs(nr, nc, grid,area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();    // no.of rows
        int m = grid[0].size(); // no. of cols
        int maxi=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int area=0;
                    dfs(i, j,grid,area);
                    maxi=max(area,maxi);
                }
            }
        }
        return maxi;
    }
};