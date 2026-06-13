class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
        vis[node] = 1; // currently in recursion path

        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                if (dfs(it, adj, vis)) {
                    return true;
                }
            }
            else if (vis[it] == 1) {
                return true; // cycle found
            }
        }

        vis[node] = 2; // fully processed
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> vis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(i, adj, vis)) {
                    return false;
                }
            }
        }

        return true;
    }
};