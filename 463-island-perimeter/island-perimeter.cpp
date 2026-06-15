class Solution {
public:
    bool isValid(int nr, int nc, int m, int n) {
        if (nr >= 0 && nr < m && nc >= 0 && nc < n)
            return true;
        return false;
    }
    int ans = 0;
    void dfs(int i, int j, vector<vector<int>>& vis,
             const vector<vector<int>>& grid) {
        vis[i][j] = 1;

        // need to check in eight direction for adjacent 1 and then call dfs on
        // that i,j
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};
        for (int k = 0; k < 4; k++) {

            int nr = i + dr[k];
            int nc = j + dc[k];
            bool flg=isValid(nr,nc,grid.size(),grid[0].size());
            if(!flg) ans++;
            else if(flg && grid[nr][nc]==0) ans++;
            else if(flg && grid[nr][nc] == 1 && !vis[nr][nc])  dfs(nr, nc, vis, grid);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, visited, grid);
                    return ans;
                }
            }
        }
        return -1;
    }
};