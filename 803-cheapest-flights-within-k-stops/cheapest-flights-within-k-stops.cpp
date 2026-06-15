
#define P pair<int, pair<int, int>>
class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                       int K) {
        // bfs da goat
        vector<vector<pair<int,int>>> adj(n);
        vector<int> dist(n,1e9);
        dist[src]=0;
        priority_queue < P, vector<P>,greater<P>> pq;  //<dist,node>
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }  // it is directed edge

        pq.push({0,{0, src}}); //stop (hard constraint) as ordered by pq so must be first, <stop<cost,node>>

        //we have to maintain the visited array right here as we don't have or we i think have the dist we musst have to return dist[n-1] at the end when we ahve the pop out from the pq having node==targetnODE AND stops-1<=k as it will have one more stop itself as couted so we need to subtract it

        while (!pq.empty()) {
            int cost = pq.top().second.first;
            int node = pq.top().second.second;
            int stop = pq.top().first;  // number of stop till now this node
            pq.pop();
            
            if (stop>K) continue;
            // traverse all 4 possible neighbors
            for (const auto& it : adj[node]) {
                int wt=it.second;
                int adjNode=it.first;

                if(cost+wt<dist[adjNode]){
                    dist[adjNode]=cost+wt;
                    pq.push({stop+1,{cost+wt,adjNode}});
                }
            }
            
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
