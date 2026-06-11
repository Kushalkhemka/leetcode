class Solution {
   public:
    void dfs(int newColor,int oldColor, int i, int j, vector<vector<int>> &vis,
              vector<vector<int>> &grid) {
        vis[i][j] = 1;
        grid[i][j] = newColor;

        // need to check in eight direction for adjacent 1 and then call dfs on
        // that i,j
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
                grid[nr][nc] == oldColor && !vis[nr][nc]) {
                dfs(newColor,oldColor, nr, nc, vis, grid);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        int n = image.size();     // no.of rows
        int m = image[0].size();  // no. of cols
        vector<vector<int>> vis(n, vector<int>(m, 0));

        dfs(newColor,image[sr][sc], sr, sc, vis, image);

        return image;
    }
};
