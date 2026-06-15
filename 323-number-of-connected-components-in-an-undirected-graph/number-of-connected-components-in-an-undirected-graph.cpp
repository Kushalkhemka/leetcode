class Solution {
public:
   void dfs(const int node, const vector<vector<int>> &adj, vector<int> &visited) {
        visited[node] = 1;
        
        for (const auto &it : adj[node]) {
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
    int dfsOfGraph(const int V, const vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);

        for (const auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);  // because graph is undirected
        }
        int cnt=0;
        vector<int> visited(V, 0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adj,visited);
            }
        }
        return cnt;
    }
    int countComponents(const int n, const vector<vector<int>>& edges) {
        return dfsOfGraph(n, edges);
    }
};