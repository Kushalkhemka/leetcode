class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // let's make the matrix first
        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        vector<int> numOfCities(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]][edge[1]] = edge[2];
            adj[edge[1]][edge[0]] = edge[2]; // undirected graph
            if (edge[2] <= distanceThreshold) {
                numOfCities[edge[0]]++;
                numOfCities[edge[1]]++;
            }
        }
        for (int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }
        // matrix is ready to apply floyd warshal

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    // since n*n graph
                    int dist = adj[j][i] + adj[i][k];
                    if (dist < adj[j][k]) {
                        if ((adj[j][k] == 1e9 ||
                            adj[j][k] > distanceThreshold) &&
                             dist <= distanceThreshold)
                            numOfCities[j]++;
                        adj[j][k] = dist;
                    }
                }
            }
        }
        int min=1e9; int ans=-1;
        for(int i=0;i<n;i++){
            if(numOfCities[i]<=min){
                min=numOfCities[i];
                ans=i;
            }
        }
        return ans;
    }
};