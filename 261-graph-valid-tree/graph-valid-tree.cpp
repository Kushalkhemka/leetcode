class DisjointSet {
   public:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {
        rank.resize(n, 0);    
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

    int unionByRank(int u, int v) {
        int uPar_u = findUPar(u);
        int uPar_v = findUPar(v);
        if (uPar_u == uPar_v) return 0;
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
        return 1;
    }

    void unionBySize(int u, int v) {
        int uPar_u = findUPar(u);
        int uPar_v = findUPar(v);
        if (uPar_u == uPar_v) return;
        if (size[uPar_u] > size[uPar_v]) {
            // smaller attach to bigger rank one
            parent[uPar_v] = uPar_u;
            size[uPar_u] += size[uPar_v];
        } else {
            //<= both cases covered as size increases in all three cases so can
            //be combined
            parent[uPar_u] = uPar_v;
            size[uPar_v] += size[uPar_u];
        }
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        bool flg1=true;
        for(const auto &e:edges){
            if(!ds.unionByRank(e[0],e[1])){
                flg1=false;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                cnt++;
            }
        }
        return flg1&&(cnt==1);
    }
};