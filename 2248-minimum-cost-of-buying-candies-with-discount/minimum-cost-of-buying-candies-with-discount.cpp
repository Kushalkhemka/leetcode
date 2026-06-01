class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int n=cost.size(); int i=0; int ans=0;
        while(i<n){
            ans=ans+cost[i];
            if(i<n-1) ans+=cost[i+1];
            i=i+3;
        }
        return ans;
    }
};