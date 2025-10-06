class Solution {
public:
    void sortColors(vector<int>& nums) {
        // three pointer go brr or lmao do quick sort
        // mauj kr di chal ab kaam kr le three pointer approach h DNF
        int i = 0;
        int j = 0;
        int k = nums.size()-1;

        // now keep i and j at starting i is for 0, j for 1 and k is for 2.
        while (j <= k) {
            if (nums[j] == 0) {
                // swap with the nums[i];
                swap(nums[j], nums[i]);
                i++;j++;

            } else if (nums[j] == 2) {
                swap(nums[j], nums[k]);
                k--;
            } else // nums[j]==1
            {
                j++;
            }
        }
    }
};