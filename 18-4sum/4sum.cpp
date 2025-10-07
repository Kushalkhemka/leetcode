class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4) return ans;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int k = i + 1; k < n - 2; k++) {
                // CHANGED: The duplicate check for k must be relative to i.
                if (k > i + 1 && nums[k] == nums[k - 1]) {
                    continue;
                }
                // CHANGED: Use long long for the target to prevent overflow.
                // Cast to long long BEFORE the arithmetic operations.
                long long derivedTarget = (long long)target - nums[i] - nums[k];
                int l = k + 1;
                int r = n - 1;
                while (l < r) {
                    // CHANGED: Calculate the two-pointer sum also as long long.
                    long long two_sum = (long long)nums[l] + nums[r];
                    if (two_sum == derivedTarget) {
                        ans.push_back({nums[i], nums[k], nums[l], nums[r]});
                        l++;
                        r--;

                        while (l < r && nums[l] == nums[l - 1]) {
                            l++;
                        }
                        while (l < r && nums[r] == nums[r + 1]) {
                            r--;
                        }
                    } else if (two_sum > derivedTarget) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};