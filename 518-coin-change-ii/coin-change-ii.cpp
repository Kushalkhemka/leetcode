class Solution {
public:
    int fn(int idx,int T, vector<int>& coins,vector<vector<int>> &dp){
        
        if(idx==0){
            return (T%coins[0]==0);
        }
        if(dp[idx][T]!=-1) return dp[idx][T];
        int not_take = fn(idx-1,T,coins,dp);
        int take=0;
        if(coins[idx]<=T){
            take=fn(idx,T-coins[idx],coins,dp);
        }
        return dp[idx][T]=not_take+take;
    }

    int change(int amount,vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return fn(coins.size()-1,amount,coins,dp);
    }
};
