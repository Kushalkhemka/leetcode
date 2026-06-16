class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        queue<tuple<int,int,int,int>> q;
        int ans = 0;
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};

        vector<vector<int>> vis(n, vector<int>(m, -1));

        q.push({0,0,0,k});
        vis[0][0] = k; 
        while (!q.empty()) {
            int qs =
                q.size(); // must be before for loop as size chnges in for loop
            for (int l = 0; l < qs; l++) {
               auto [r, c, d, obs] = q.front();
                q.pop();

                if (r == n-1 && c == m-1)
                    return d;

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i]; 
                    int nc = c + dc[i]; 
                    bool flg=nr >= 0 && nr < n && nc >= 0 && nc < m;

                    if (flg && grid[nr][nc] == 0) {
                        if (obs <= vis[nr][nc]) continue; //skip only if this cell was reached with better/equal obs left

                        if (nr == n-1 && nc == m-1)
                            return d + 1;

                        vis[nr][nc] = obs; 
                        q.push({nr, nc, d + 1, obs});
                    }
                    else if(flg && grid[nr][nc] == 1 && obs > 0) {

                        if (obs - 1 <= vis[nr][nc]) continue; 
                        if (nr == n-1 && nc == m-1)
                            return d + 1;

                        vis[nr][nc] = obs - 1; 
                        q.push({nr, nc, d + 1, obs - 1}); 
                    }
                }
            }
        }
        return -1;
    }
};