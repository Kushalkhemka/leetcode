#define P pair<long long, int>

class Solution {
public:
    int countPaths( const int n,const vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n); // 1based indexing
        const int MOD = 1e9 + 7;
        for (const auto& edge : roads) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]}); // undirected edge
        }
        priority_queue<P, vector<P>, greater<P>>
            pq; //<dist,node> as ordered by pair.first which is dist in the pq
        vector<long long> dis(n, 1e18); // initialised with inf time
        vector<int> ways(n, 0);
        ways[0] = 1;
        dis[0] = 0;
        // push the source node
        pq.push({0, 0});
      
        // djikshtra algo
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            int node = x.second;
            long long dist = x.first; // dis is the wt till this popped node from the
                               // source K node
            if (dist > dis[node])
                continue;
        
            for (const auto& it : adj[node]) {
                // push the adj node if they have smaller time of replication
                // through some other path or initially push
                int wt = it.second;
                int adjNode =
                    it.first; // wt is the weight between node and its adjNode
                if(dist + wt == dis[adjNode]) ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                //if the shortest path merges into then then the number of the ways is the number of ways till now+ number of ways as adj node
                if (dist + wt < dis[adjNode]) {
                    ways[adjNode]=ways[node];
                    dis[adjNode] = dist + wt;
                    pq.push({dist + wt, adjNode});
                }
            }
        }
        return ways[n-1];
    }
};