

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
    int removeStones(vector<vector<int>>& stones) {
        vector<pair<int, int>> edges;
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    edges.push_back({i, j});
                }
            }
        }

        DisjointSet ds(n);
        for (const auto& edge : edges) {
            ds.unionByRank(edge.first, edge.second);
        }

        int connectedComponents = 0; // equals to UPars
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i)
                connectedComponents++;
        }

        return n - connectedComponents;
    }
};