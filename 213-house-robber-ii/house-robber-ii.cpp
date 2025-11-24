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

        vector<int> temp1;
        vector<int> temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }

        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);
        return max(f((int)temp1.size() - 1, temp1, dp1),
                   f((int)temp2.size() - 1, temp2, dp2));
    }
};
