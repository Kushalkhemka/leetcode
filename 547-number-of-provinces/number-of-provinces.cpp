class Solution {
public:
   void dfs(int node, const vector<vector<int>> &adj, vector<int> &visited) {
        visited[node] = 1;

        //handle adjacency matrix instead of adjacency list
        for(int i=0;i<adj[0].size();i++){
            if(i==node) continue; //self connection is ignored
            if(adj[node][i]==1 && !visited[i]){
                dfs(i,adj,visited);
            }
        }
    }
    int dfsOfGraph(const int V, const vector<vector<int>> &adj) {
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
    int findCircleNum(vector<vector<int>>& adj) {
       //1-based indexing (but in this question no difference on ans even if we consider 0 based indexing as all shift by -1 offset,connection is invariant)
        return dfsOfGraph(adj.size(),adj);
       
    }
    
};