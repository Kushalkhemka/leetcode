
class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1; //optimisation 
        if(n==1) return 1;
        queue<pair<int, int>> q;
        int ans = 1;
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        q.push({0, 0});
        grid[0][0] = 1;
        while (!q.empty()) {
            int qs =
                q.size();  // must be before for loop as size chnges in for loop
            for (int l = 0; l < qs; l++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if (r == n - 1 && c == n - 1) return ans; // changed

                for (int k = 0; k < 8; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            ans++;
           
        }
        return -1;
    }
    
};