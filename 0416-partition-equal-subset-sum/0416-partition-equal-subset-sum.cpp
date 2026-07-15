

class Solution {
public:
    bool fn(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if (sum == 0)
            return true;
        if (idx == arr.size() || sum < 0)
            return false;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        bool take = false;
        if (sum > 0) {
            take = fn(idx + 1, sum - arr[idx], arr, dp);
        }

        bool nottake = fn(idx + 1, sum, arr, dp);

        return dp[idx][sum] = (take || nottake);
    }
    bool canPartition(vector<int>& arr) {

        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if (totalSum % 2 != 0)
            return false;
        // make sured it is even as
        int targetSum = totalSum / 2;
        vector<vector<int>> dp(arr.size(), vector<int>(targetSum + 1, -1));
        return fn(0, targetSum, arr, dp);
    }
};