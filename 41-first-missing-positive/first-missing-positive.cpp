class Solution {
public:
    // Question Needs the cyclic sort
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            // CHANGED: The last part of the condition is now more robust.
            // It checks if the number at the current spot is the same as the
            // number at its target destination. If they are the same, we don't swap.
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[nums[i] - 1], nums[i]);
            } else {
                i++;
            }
        }

        // This second part of your code is perfectly correct.
        for (int j = 0; j < n; j++) {
            if (nums[j] != j + 1) {
                return j + 1;
            }
        }
        return n + 1;
    }
};