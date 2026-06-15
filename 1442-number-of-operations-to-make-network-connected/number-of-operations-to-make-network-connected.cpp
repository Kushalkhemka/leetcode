

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
    int makeConnected(int n, vector<vector<int>>& Edge) {
        if (Edge.size() < n - 1)
            return -1;     // changed: minimum edges required
        DisjointSet ds(n); // 0 based indexing so no issue
        // process all edges to do the unionByRank
        for (const auto& e : Edge) {
            ds.unionByRank(e[0], e[1]);
        }
        int ans = 0;
        // now we have to return the number of ultimate Parent minus 1
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i)
                ans++;
        }
        return ans - 1;
    }
};
