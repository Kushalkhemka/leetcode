class Solution {
public:
    int fn(int idx,int prev, vector<int>& nums,vector<vector<int>> &dp){
        int n=nums.size();
        if(idx==n) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int not_take=0+fn(idx+1,prev,nums,dp);
        int take=INT_MIN;
        if(prev==-1 || nums[prev]<nums[idx]){
            take=1+fn(idx+1,idx,nums,dp);
        }
        return dp[idx][prev+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fn(0,-1,nums,dp);
    }
};