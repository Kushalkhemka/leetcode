class Solution {
public:
    int power(int base, int exp) {
        int ans = base;
        int MOD = 1e9 + 7;
        for (int i = 0; i < exp - 1; i++) {
            ans = (ans * base) % MOD;
        }

        if (exp < 1)
            ans = 1;
        return ans % MOD;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1); // n+1 as it is 1 based tree rooted
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

            // undirected graph tree haha
        }
        int maxDepth = 0;
        // now either do the inorder or bfs to get the depth of each node and
        // get the max depth

        queue<int> q;
        q.push(1);
        vector<int> visited(n + 1, 0);
        visited[1] = 1;
        while (!q.empty()) {
            int qs = q.size();

            for (int i = 0; i < qs; i++) {
                int node = q.front();
                q.pop();

                // now check the neighbors of the q and push it and increase the
                // depth
                for (auto& it : adj[node]) {
                    if (!visited[it]) {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
            maxDepth++;
        }

        return power(2, maxDepth - 2);
    }
};