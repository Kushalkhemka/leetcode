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

        int buildDr[] = {0, 1}; // changed: separate directions for DSU build, right and down only
        int buildDc[] = {1, 0}; // changed: separate directions for DSU build, right and down only

        int dr[] = {0, 1, -1, 0};
        int dc[] = {1, 0, 0, -1};

        bool hasZero = false; // changed: avoids storing all zero positions

        // Step 1: Build DSU for all existing 1-connected components
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    hasZero = true; // changed: only track whether zero exists
                    continue;
                }

                int node = r * n + c;

                for (int i = 0; i < 2; i++) {
                    int nr = r + buildDr[i]; // changed: using buildDr
                    int nc = c + buildDc[i]; // changed: using buildDc

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {
                        int adjNode = nr * n + nc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        if (!hasZero) {
            return m * n; // changed: simpler all-ones case
        }

        // Step 2: Try converting every 0 to 1
        for (int r = 0; r < m; r++) { // changed: directly scanning grid again instead of Zeroes vector
            for (int c = 0; c < n; c++) { // changed: directly scanning grid again
                if (grid[r][c] == 1)
                    continue; // changed: only process zero cells

                int ans = 1; // changed: start from 1 because we are flipping current 0
                vector<int> parents; // changed: lighter than unordered_set because max 4 parents only

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {
                        int adjNode = nr * n + nc;
                        int uPar = ds.findUPar(adjNode);

                        bool alreadyAdded = false; // changed: manual duplicate check
                        for (int p : parents) { // changed: at most 4 elements, so this is cheap
                            if (p == uPar) {
                                alreadyAdded = true;
                                break;
                            }
                        }

                        if (!alreadyAdded) {
                            parents.push_back(uPar); // changed: add unique parent only
                            ans += ds.size[uPar];    // changed: add size immediately
                        }
                    }
                }

                maxi = max(maxi, ans);
            }
        }

        return maxi;
    }
};