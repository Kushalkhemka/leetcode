class Solution {
public:
    // Question Needs the cyclic sort
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            //instead of nums[i]!=(i+1) use the nums[i] != nums[nums[i] - 1] condition to also handle the duplicate if the duplicate element is already at place then we don't need to swap again and thus avoid tle error preventing the infinite loop
            //use cyclic sort and then just traverse from 0 to n-1 and check if element is  at correct index if not then return the index value (so we are returning the first such occurence) (this is done after sorting to ensure we are returning the missing number);
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[nums[i] - 1], nums[i]);
            } else {
                i++;
            }
        }

        for (int j = 0; j < n; j++) {
            if (nums[j] != j + 1) {
                return j + 1;
            }
        }
        return n + 1;
    }
};