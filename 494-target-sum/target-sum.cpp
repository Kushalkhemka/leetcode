class Solution {
public:
    int fn(int idx, const vector<int>& nums, int target, vector<vector<int>>& dp, int sum) {
        if (target < -sum || target > sum) return 0;
        if (idx < 0) {
            return target == 0; 
        }

        if (dp[idx][target + sum] != -1) {
            return dp[idx][target + sum]; 
        }

        // take +
        int plus = fn(idx - 1, nums, target - nums[idx], dp, sum); 

        // take -
        int minus = fn(idx - 1, nums, target + nums[idx], dp, sum); 

        return dp[idx][target + sum] = plus + minus; 
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0; 
        for (int x : nums) sum += x;

        if (target < -sum || target > sum) return 0; 

        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1)); 
        return fn(nums.size() - 1, nums, target, dp, sum); 
    }
};