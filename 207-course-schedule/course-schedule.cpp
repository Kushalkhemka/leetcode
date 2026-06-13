class Solution {
public:
    bool ans = false;
    void dfs(int node, const vector<vector<int>> &adj, vector<int> &visited,
             vector<int> &pathVis) {
        if(ans) return;
        visited[node] = 1;
        pathVis[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited, pathVis);
            } else {
                if (pathVis[it]) {
                    ans =true;
                }
            }
        }
        pathVis[node] = 0;
    }

    bool isCyclic(int N, const vector<vector<int>> &adj) {
        vector<int> vis(N, 0);
        vector<int> pathVis(N, 0);
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, pathVis);
            }
        }
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]); //graph is directed now
        }
        return !isCyclic(numCourses,adj);
    }
};
