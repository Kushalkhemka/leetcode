class Solution {
public:
    vector<vector<int>> up;
    int LOG;
    vector<int> depth;

    int power(int base, int exp) {
        long long ans = 1;
        long long curr = base;
        int MOD = 1e9 + 7;

        while (exp > 0) {
            if (exp & 1) {
                ans = (ans * curr) % MOD;
            }

            curr = (curr * curr) % MOD;
            exp >>= 1;
        }

        return ans;
    }

    void treeAncestor(int n, vector<int>& parent) {
        // time for the binary lifting guys
        LOG = log2(n) + 1;

        up.assign(n, vector<int>(LOG, -1)); // changed: properly reset the table

        // fill the first col of the up ancestor table
        for (int i = 1; i < parent.size(); i++) {
            up[i][0] = parent[i];
        }

        // now apply the dp
        for (int j = 1; j < LOG; j++) {
            for (int k = 1; k < n; k++) {
                // main recurrence relation for binary lifting
                if (up[k][j - 1] != -1) {
                    up[k][j] = up[up[k][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        int i = 0;

        while (k > 0 && node != -1) {
            if (k & 1) {
                node = up[node][i];
            }

            k >>= 1;
            i++;
        }

        return node;
    }

    // both nodes must already be at the same depth
    int getLCADist(int u, int v) {
        int jumps = 0; // changed: total upward movement by one node

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != -1 && up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];

                jumps += (1 << j); // changed: actual jump is 2^j
            }
        }

        // changed: final one edge from each node to LCA
        return 2 * (jumps + 1);
    }

    int processQuery(int u, int v, int depthU, int depthV) {
        if (u == v)
            return 0;

        int dist = 0; // changed: total edges between original nodes

        // first bring both nodes to the same depth
        if (depthU < depthV) {
            int diff = depthV - depthU;
            v = getKthAncestor(v, diff);

            dist += diff; // changed: count the initial depth difference
        } else if (depthU > depthV) {
            int diff = depthU - depthV;
            u = getKthAncestor(u, diff);

            dist += diff; // changed: count the initial depth difference
        }

        // changed: one node is an ancestor of the other
        if (u == v) {
            return power(2, dist - 1);
        }

        dist += getLCADist(u, v); // changed: remaining path through LCA

        return power(2, dist - 1);
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        vector<int> parent(n + 1, -1);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

            // undirected graph tree haha
        }

        int maxDepth = 1;

        queue<int> q;
        q.push(1);

        vector<int> visited(n + 1, 0);
        depth.assign(n + 1, 0);

        visited[1] = 1;

        while (!q.empty()) {
            int qs = q.size();

            for (int i = 0; i < qs; i++) {
                int node = q.front();
                q.pop();

                for (auto& it : adj[node]) {
                    if (!visited[it]) {
                        parent[it] = node;
                        depth[it] = maxDepth;
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }

            maxDepth++;
        }

        treeAncestor(n + 1, parent);

        vector<int> ans;

        for (auto& q : queries) {
            ans.push_back(processQuery(q[0], q[1], depth[q[0]], depth[q[1]]));
        }

        return ans;
    }
};