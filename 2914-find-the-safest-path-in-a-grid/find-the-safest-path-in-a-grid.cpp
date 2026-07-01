#define P pair<int, pair<int, int>>
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < n && nc < m && nr >= 0 && nc >= 0 &&
                    dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // now we have the dist let's make the priority
        priority_queue<P> pq;
        vector<vector<int>> best(n, vector<int>(m, -1));
        
        pq.push({dist[0][0], {0, 0}});
        while (!pq.empty()) {
            int safeness = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == n - 1 && c == m - 1) {
                return safeness; 
            }

            if (safeness < best[r][c]) continue;         

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < n && nc < m && nr >= 0 && nc >= 0) {
                    int newSafeness=min(safeness,dist[nr][nc]);
                    if(newSafeness>best[nr][nc]){
                        best[nr][nc]=newSafeness;
                        pq.push({newSafeness,{nr, nc}});
                    }
                    
                }
            }

        }
        return -1;
    }
};