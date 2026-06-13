class Solution {
   public:
    bool dfs(int node, const vector<vector<int>> &adj, vector<int>& visited) {
        visited[node] = 1;  // current path

        for (const auto &it : adj[node]) {
            if (visited[it] == 0) {
                if (dfs(it, adj, visited)) {
                    visited[node] = 3;  // child unsafe, so current unsafe
                    return true;
                }
            } else if (visited[it] == 1 || visited[it] == 3) {
                visited[node] = 3;  // cycle/unsafe neighbour found
                return true;
            }
        }

        visited[node] = 2;  // safe
        return false;
    }

    vector<int> eventualSafeNodes(const vector<vector<int>> &adj) {
        int V=adj.size();
        vector<int> ans;
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                dfs(i, adj, visited);
            }
        }

        for (int i = 0; i < V; i++) {
            if (visited[i] == 2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};