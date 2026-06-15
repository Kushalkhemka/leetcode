class DisjointSet {
public:
    vector<int> rank;
    vector<int> parent;
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = findUPar(parent[u]);
    }

    void unionByRank(int u, int v) {
        int uPar_u = findUPar(u);
        int uPar_v = findUPar(v);
        if (uPar_u == uPar_v)
            return;
        if (rank[uPar_u] > rank[uPar_v]) {
            // smaller attach to bigger rank one
            parent[uPar_v] = uPar_u;
        } else if (rank[uPar_u] < rank[uPar_v]) {
            parent[uPar_u] = uPar_v;
        } else {
            parent[uPar_u] = uPar_v;
            // upar_v attach to upar_u so rank of upar_u increass
            rank[uPar_u]++;
        }
    }
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, const vector<vector<int>>& positions) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<int> ans;
        DisjointSet ds(m * n);
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};
        int cnt = 0;

        for (auto x : positions) {
            int r = x[0];
            int c = x[1];

            if (grid[r][c] == 1) { // to avoid duplicate grid[i][j] processing
                ans.push_back(cnt);
                continue;
            }

            grid[r][c] = 1;
            cnt++;

            int node = r * n + c;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    grid[nr][nc] == 1) {
                    int adjNode = nr * n + nc;

                    if (ds.findUPar(node) != ds.findUPar(adjNode)) {
                        ds.unionByRank(node, adjNode);
                        cnt--;
                    }
                }
            }

            ans.push_back(cnt);
        }
        return ans;
    }
};
