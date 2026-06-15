#define P pair<int, int>
class Solution {
public:
    int networkDelayTime(const vector<vector<int>>& times, const int n,
                         const int k) {
        vector<vector<pair<int, int>>> adj(n + 1); // 1based indexing
        for (const auto& edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]}); // directed edge
        }
        priority_queue<P, vector<P>, greater<P>>
            pq; //<dist,node> as ordered by pair.first which is dist in the pq
        vector<int> time(n + 1, 1e9); // initialised with inf time
        time[k] = 0;
        // push the source node
        pq.push({0, k});

        // djikshtra algo
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            int node = x.second;
            int dis = x.first; // dis is the wt till this popped node from the
                               // source K node
            if (dis > time[node])
                continue;
            for (const auto& it : adj[node]) {
                // push the adj node if they have smaller time of replication
                // through some other path or initially push
                int wt = it.second;
                int adjNode =
                    it.first; // wt is the weight between node and its adjNode
                if (dis + wt < time[adjNode]) {
                    time[adjNode] = dis + wt;
                    pq.push({dis + wt, adjNode});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (time[i] == 1e9)
                return -1; // changed
            ans = max(ans, time[i]);
        }
        return ans;
    }
};