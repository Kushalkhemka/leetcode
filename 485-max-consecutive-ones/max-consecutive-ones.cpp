class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // sliding window approach (collapsible)
        int n = nums.size();
        int i = 0;
        int count = 0;
        int tempCount = 0;
        for (int j = 0; j < n; j++) {
            // sliding window
            if (nums[j] == 1)
                tempCount++; // expanding the window
            if (nums[j] == 0) {
                count = max(count, tempCount);
                tempCount = 0;
               
            }
        }
        return max(count, tempCount);;
    }
};