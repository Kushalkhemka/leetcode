class Solution {
   public:
    void dfs(int i, int j, vector<vector<int>> &vis,
             const vector<vector<int>> &grid) {
        vis[i][j] = 1;

        // need to check in eight direction for adjacent 1 and then call dfs on
        // that i,j
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
                grid[nr][nc] == 1 && !vis[nr][nc]) {
                dfs(nr, nc, vis, grid);
            }
        }
    }
    int numEnclaves(const vector<vector<int>> &grid) {
        int n = grid.size();     // no.of rows
        int m = grid[0].size();  // no. of cols
        vector<vector<int>> vis(n, vector<int>(m, 0));

        //cover top and bottom boundary
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !vis[0][i]){
                dfs(0,i,vis,grid);
            }
            if(grid[n-1][i]==1 && !vis[n-1][i]){
                dfs(n-1,i,vis,grid);
            }
        }
        //cover left and right boundary
        for(int i=1;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,vis,grid);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(i,m-1,vis,grid);
            }
        }
        //count uncovered enclaves (the land cell grid[i][j]==1) from which moving up & left & down &right (all four must be satisfied) once doesn't go out of the grid in any case.
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
