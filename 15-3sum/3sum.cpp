class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int originalTarget = 0; // This can be removed, as the target is always 0.
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int derivedTarget = 0 - nums[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] == derivedTarget) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    
                    // CHANGED: This is the robust and safe way to skip duplicates.
                    // It compares the new pointer position to the one we just used.
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                } else if (nums[l] + nums[r] > derivedTarget) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};