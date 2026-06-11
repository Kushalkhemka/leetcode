class Solution {
   public:
    void solve(vector<vector<char>> &mat) {
        // use multi source bfs with the edge O's in queue initially also
        // replace them by # and then do 2D travesal and change # to O and O to
        // X and return it;

        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};

        // visited array work is done by changing O to # that is req to visit
        // rest are even not req to visit cover top and bottom boundary
        for (int i = 0; i < m; i++) {
            if (mat[0][i] == 'O') {
                mat[0][i] = '#';
                q.push({0, i});
            }
            if (mat[n - 1][i] == 'O') {
                mat[n - 1][i] = '#';
                q.push({n-1, i});
            }
        }
        // cover left and right boundary
        for (int i = 1; i < n-1; i++) {
            if (mat[i][0] == 'O') {
                mat[i][0] = '#';
                q.push({i, 0});
            }
            if (mat[i][m - 1] == 'O') {
                mat[i][m-1] = '#';
                q.push({i, m-1});
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
                        mat[nr][nc] == 'O') {
                        mat[nr][nc] = '#';
                        q.push({nr, nc});
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'O') {
                    // add all rotten oranges into the bfs for multi source bfs
                    mat[i][j]='X';
                } else if (mat[i][j] == '#') {
                    mat[i][j]='O';
                }
            }
        }

       
        
    }
};