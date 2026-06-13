class Solution {
public:
    bool dfs(int node,const vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1; // currently in recursion path

        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                if (dfs(it, adj, vis)) {
                    return true;
                }
            } else if (vis[it] == 1) {
                return true; // cycle found
            }
        }

        vis[node] = 2; // fully processed
        return false;
    }

    bool canFinish(int numCourses, const vector<vector<int>>& graph) {
       
        vector<int> vis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(i, graph, vis)) {
                    return false;
                }
            }
        }
        return true;
    }
    void dfs(int node, const vector<vector<int>>& adj, vector<int>& visited,
             stack<int>& s) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited, s);
            }
        }
        s.push(node);
    }

    vector<int> topoSort(const int V, const vector<vector<int>>& adj) {
        // 0 based indexed graph
        stack<int> s;
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, s);
            }
        }
        vector<int> ans;
        while (!s.empty()) {
            int temp = s.top();
            s.pop();
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        if(!canFinish(numCourses,adj)) return {};
        return topoSort(numCourses, adj);
    }
};
