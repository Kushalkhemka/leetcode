class Solution{
public:
    bool ans=true;
    void dfs(int node, const vector<vector<int>> &adj,vector<int> &color) {
        if (!ans) return;
        for (auto it : adj[node]) {
            //here node is the parent so we need to assign opp color if not assigned or else check the color to be opposite of it other return false and take && with ans
            if(color[it]==-1){
                color[it]=!color[node];
                dfs(it,adj,color);
            }
            else //it have some coloir assigned
            {
                if(color[it]==color[node]) ans=ans&&false; 
            }
        }
    }

    bool isBipartite(const vector<vector<int>> &graph)  {
       
        //color 0,1
        vector<int> color(graph.size(),-1);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i]==-1) {
                dfs(i, graph, color);
            }
        }

        return ans;
    }
};
