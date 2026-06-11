class Solution {
   public:
    void dfs(int newColor,int oldColor, int i, int j,
              vector<vector<int>> &grid) {
    
        grid[i][j] = newColor;

        // need to check in four direction for adjacent 1 and then call dfs on
        // that i,j
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
                grid[nr][nc] == oldColor) {
                dfs(newColor,oldColor, nr, nc, grid);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        int n = image.size();     // no.of rows
        int m = image[0].size();  // no. of cols
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;
        dfs(newColor,oldColor, sr, sc, image);

        return image;
    }
};
