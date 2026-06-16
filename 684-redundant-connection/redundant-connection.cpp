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
    bool find(int u, int v) { return findUPar(u) == findUPar(v); }

    int unionByRank(int u, int v) {
        int uPar_u = findUPar(u);
        int uPar_v = findUPar(v);
        if (uPar_u == uPar_v) return 0; //means already belong to same component
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
        return 1; //means successful union 
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(1001);

        for(auto&edge:edges){
            if(!ds.unionByRank(edge[0],edge[1])){
                return {edge[0],edge[1]};
            }
        }
        return {}; //unreachable as per constraint
    }

    
};