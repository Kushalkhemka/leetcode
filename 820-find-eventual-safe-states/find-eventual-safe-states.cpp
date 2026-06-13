class Solution {
   public:
    void dfs(int node, const vector<vector<int>> &adj, vector<int>& visited,
             vector<int>& ans) {
        visited[node] = 1;  // current pathVis so visited[node]=1
        for (const auto& it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited, ans);

                if (visited[it] == 3) {  // if child is unsafe, current node is also unsafe
                    visited[node] = 3;   
                }

            } else {
                if (visited[it] == 1 || visited[it] == 3) {
                    // cycle mil gyi to vis me jo bi 1 h unhe ban kr do
                    // permanently for loop
                    for (int i = 0; i < visited.size(); i++) {
                        if (visited[i] == 1)
                            visited[i] = 3;  // 3 means banned it can't be safe
                                             // as one of the path of it's end
                                             // in a non terminal state
                    }
                }
            }
        }
        if (visited[node] == 1)
            visited[node] = 2;  // full processed only if it's not banned
        if (visited[node] == 2) ans.push_back(node);
    }

    vector<int> eventualSafeNodes(const vector<vector<int>> &adj) {
        vector<int> ans;
        vector<int> visited(adj.size(), 0);
        for (int i = 0; i < adj.size(); i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, ans);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};