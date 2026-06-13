class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                if (dfs(it, adj, vis, ans)) return true;
            }
            else if (vis[it] == 1) {
                return true;
            }
        }

        vis[node] = 2;
        ans.push_back(node); // changed: push after processing all prerequisites
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(i, adj, vis, ans)) return {};
            }
        }

        return ans;
    }
};