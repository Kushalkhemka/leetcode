class DisjointSet {
public:
    vector<int> size;
    vector<int> parent;

    DisjointSet(int n) {
        size.resize(n, 1);
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

    void unionBySize(int u, int v) {
        int uPar_u = findUPar(u);
        int uPar_v = findUPar(v);

        if (uPar_u == uPar_v) {
            return;
        }

        if (size[uPar_u] < size[uPar_v]) {
            parent[uPar_u] = uPar_v;
            size[uPar_v] += size[uPar_u];
        } else {
            parent[uPar_v] = uPar_u;
            size[uPar_u] += size[uPar_v];
        }
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, const vector<vector<int>>& positions) {
        vector<char> grid(m * n, 0); // changed: 1D visited grid instead of 2D grid
        vector<int> ans;
        ans.reserve(positions.size()); // changed: avoids repeated vector reallocations

        DisjointSet ds(m * n);

        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};

        int cnt = 0;

        for (const auto& x : positions) { // changed: avoid copying each position vector
            int r = x[0];
            int c = x[1];

            int node = r * n + c; // changed: calculate node before duplicate check

            if (grid[node] == 1) { // changed: duplicate check using 1D grid
                ans.push_back(cnt);
                continue;
            }

            grid[node] = 1; // changed: mark land in 1D grid
            cnt++;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int adjNode = nr * n + nc;

                    if (grid[adjNode] == 1 &&
                        ds.findUPar(node) != ds.findUPar(adjNode)) {
                        ds.unionBySize(node, adjNode);
                        cnt--;
                    }
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};