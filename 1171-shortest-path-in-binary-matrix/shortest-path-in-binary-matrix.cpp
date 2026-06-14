
class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        if(grid[0][0]!=0) return -1; //optimisation 
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1) return 1;
        queue<vector<int>> q;
        int ans = 0;
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        q.push({0, 0, 0});
        grid[0][0] = 2;
        while (!q.empty()) {
            int qs =
                q.size();  // must be before for loop as size chnges in for loop
            for (int l = 0; l < qs; l++) {
                int r = q.front()[0];
                int c = q.front()[1];
                int d = q.front()[2];
                q.pop();

                for (int k = 0; k < 8; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        grid[nr][nc] == 0) {
                        if(nr==n-1 && nc==n-1) return d+2;
                        grid[nr][nc] = 2;
                        q.push({nr, nc,d+1});
                    }
                }
            }
           
        }
        return -1;
    }
    
};