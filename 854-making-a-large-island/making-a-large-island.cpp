class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {

        parent.resize(n);
        size.resize(n, 1);
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
    bool find(int u, int v) { return findUPar(u) == findUPar(v); }

    void unionBySize(int u, int v) {
        int uPar_u = findUPar(u);
        int uPar_v = findUPar(v);
        if (uPar_u == uPar_v)
            return;
        if (size[uPar_u] > size[uPar_v]) {
            // smaller attach to bigger rank one
            parent[uPar_v] = uPar_u;
            size[uPar_u] += size[uPar_v];
        } else {
            //<= both cases covered as size increases in all three cases so can
            // be combined
            parent[uPar_u] = uPar_v;
            size[uPar_v] += size[uPar_u];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        int m = grid.size();
        int n = grid[0].size(); // number of cols
        // our formula is nr*n+nc , r*n+c this is for all 0 cols
        DisjointSet ds(m * n);
        int dr[] = {0, 1,-1,0};
        int dc[] = {1, 0,0,-1};
        vector<pair<int, int>> Zeroes;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0)
                    Zeroes.push_back({r, c});
                else if (grid[r][c] == 1) {
                    // call union
                    int node = r * n + c;
                    for (int i = 0; i < 2; i++) {
                        int nr = r + dr[i];
                        int nc = c + dc[i];

                        if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                            grid[nr][nc] == 1) {
                            int adjNode = nr * n + nc;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }
        if(Zeroes.size()==0) {
            //means no zeros just return the island area
            return ds.size[ds.findUPar(0)];
        }
        for (auto& z : Zeroes) {
            int node = z.first * n + z.second;
            int ans = 0;
            unordered_set<int> st;
            for (int i = 0; i < 4; i++) {
                int nr = z.first + dr[i];
                int nc = z.second + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc]==1) {
                    int adjNode = nr * n + nc;
                    st.insert(ds.findUPar(adjNode));
                }
            }
            for (int u_pars : st) {
                ans += ds.size[u_pars];
            }
            maxi = max(ans + 1, maxi);
        }
        return maxi;
    }
};