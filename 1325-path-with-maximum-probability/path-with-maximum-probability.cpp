class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        //djikshtra pil gya
                vector<vector<pair<int, double>>> adj(n);
        vector<double> dist(n, 0);  //initial prob 0
        dist[start_node] = 1; //source prob =1

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }  // it is undirected edge

        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;  //<dist,node>

        pq.push({1, start_node});

        while (!pq.empty()) {
            int node = pq.top().second;
            double d = pq.top().first;

            pq.pop();

            if (d < dist[node]) continue; 

            for (const auto& it : adj[node]) {
                int adjNode = it.first;   
                double wt = it.second;     

                if (d * wt > dist[adjNode]) {  
                    dist[adjNode] = d * wt;    
                    pq.push({dist[adjNode], adjNode}); 
                }
            }
        }

        return dist[end_node];
    }
};