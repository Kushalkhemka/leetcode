class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //make the adjoint array and check for the edge with outdegre=0
        vector<pair<int,int>> seen(n+1); //<indegree,outdegree>
        for(auto&edge:trust){
            seen[edge[0]].second++;
            seen[edge[1]].first++;
        }
        for(int i=1;i<n+1;i++){
            if(seen[i].second==0 && seen[i].first==n-1) return i;
        }
        return -1;
    }
};