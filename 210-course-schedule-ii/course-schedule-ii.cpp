class Solution {
public:
    bool dfs(const int node, const vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans) {
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
        ans.push_back(node); //push into the vector (not stack as this question demands reverse of what is usually a topological order)

        //furthermore state 2 means completely processed and when the dfs of a node is completed we just push into the stack that is the kahn algo intution simple.
        return false;
    }

    vector<int> findOrder(const int numCourses,const vector<vector<int>>& prerequisites) {
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