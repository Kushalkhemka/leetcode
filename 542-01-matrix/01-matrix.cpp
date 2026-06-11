class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};

        vector<vector<int>> dist(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    dist[i][j]=0;
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            int qs =
                q.size();  // must be before for loop as size chnges in for loop
           
            for (int l = 0; l < qs; l++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        dist[nr][nc]==-1) {
                        // dist[nr][nc]=dist[r][c]+abs(r-nr)+abs(c-nc);
                        dist[nr][nc] = dist[r][c] + 1;//abs(r-nr)+abs(c-nc) always come out to be 1
                        q.push({nr, nc});
                    }
                }
            }
           
        }

        return dist;

        
        
    }
};  