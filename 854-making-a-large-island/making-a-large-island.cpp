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

    void unionBySize(int u, int v) {
        int uPar_u = findUPar(u);
        int uPar_v = findUPar(v);

        if (uPar_u == uPar_v)
            return;

        if (size[uPar_u] > size[uPar_v]) {
            parent[uPar_v] = uPar_u;
            size[uPar_u] += size[uPar_v];
        } else {
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
        int n = grid[0].size();

        DisjointSet ds(m * n);

        int buildDr[] = {0, 1}; 
        int buildDc[] = {1, 0}; 

        int dr[] = {0, 1, -1, 0};
        int dc[] = {1, 0, 0, -1};

        bool hasZero = false; 
        // Step 1: Build DSU for all existing 1-connected components
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    hasZero = true; 
                    continue;
                }

                int node = r * n + c;

                for (int i = 0; i < 2; i++) {
                    int nr = r + buildDr[i]; 
                    int nc = c + buildDc[i]; 

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {
                        int adjNode = nr * n + nc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        if (!hasZero) {
            return m * n;
        }

        // Step 2: Try converting every 0 to 1
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) { 
                if (grid[r][c] == 1)
                    continue; 

                int ans = 1;
                vector<int> parents;

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {
                        int adjNode = nr * n + nc;
                        int uPar = ds.findUPar(adjNode);

                        bool alreadyAdded = false; 
                        for (int p : parents) { 
                            if (p == uPar) {
                                alreadyAdded = true;
                                break;
                            }
                        }

                        if (!alreadyAdded) {
                            parents.push_back(uPar); 
                            ans += ds.size[uPar];   
                        }
                    }
                }

                maxi = max(maxi, ans);
            }
        }

        return maxi;
    }
};