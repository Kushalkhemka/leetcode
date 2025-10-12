class Solution {
public:
    // Question Needs the cyclic sort
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        // we have to sort 1 to N if nums[i]>N then just ignore it and i++;
        int i = 0;
        while (i < n) {
            long long correct_idx = (long long)nums[i] - 1;
            if (correct_idx >= 0 && correct_idx < n && nums[i] != nums[correct_idx]) {
                // we need to swap with correct index
                // correct index is
                 swap(nums[i], nums[correct_idx]);
            } else {
                i++;
            }
        }

        // iterate if the element at ith position is i+1 then move forward
        // iother wise return i+1;
        for (int j = 0; j < n; j++) {
            if (nums[j] != j + 1) {
                return j + 1; // The first place where the number doesn't match
                              // the expected `j+1`.
            }
        }
        return n + 1;
    }
};