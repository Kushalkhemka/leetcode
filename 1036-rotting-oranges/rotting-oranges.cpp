class Solution {
   public:
    int orangesRotting(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int min = 0;
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};
        int fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    // add all rotten oranges into the bfs for multi source bfs
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while (!q.empty()) {
            int qs =
                q.size();  // must be before for loop as size chnges in for loop
            int flag = 0;
            for (int l = 0; l < qs; l++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        flag = 1;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            if (flag) min++;
            flag = 0;
        }

        if(fresh) return -1;

        return min;
    }
};