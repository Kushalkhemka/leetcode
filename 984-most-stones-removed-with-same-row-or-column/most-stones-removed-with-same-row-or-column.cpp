

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
       
        unordered_set<int> nodes;

         /* To store the maximum row 
        and column having a stone */
        int maxRow = 0;
        int maxCol = 0;
        
        // Iterate on all the nodes
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

         DisjointSet ds(maxRow+maxCol+2);
        

        for (auto& it : stones) {
            int row = it[0];
            int col =
                it[1] +
                maxRow+1; 
            ds.unionByRank(row,
                           col); 
            nodes.insert(row);  
            nodes.insert(col);   
        }

        int connectedComponents = 0;

        for (auto node : nodes) {
            if (ds.findUPar(node) ==
                node) { 
                connectedComponents++;
            }
        }

        return stones.size() - connectedComponents;
    }
};