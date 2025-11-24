class Solution {
public:
    int f(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx == 0)
            return nums[0];
        if (idx < 0)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int n_1 = nums[idx] + f(idx - 2, nums, dp);
        int n_2 = 0 + f(idx - 1, nums, dp);

        return dp[idx] = max(n_1, n_2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp(nums.size(),-1);
        return f(nums.size()-1,nums,dp);
    }
};
