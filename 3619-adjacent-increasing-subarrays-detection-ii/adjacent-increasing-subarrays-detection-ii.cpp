class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0; // CHANGED: Cannot form two subarrays if the input is too
                      // small.
        }
        int ans = 1;
        int l = 0;
        int n = nums.size();
        int minK, maxK;
        while (l < n) {
            int r = l;
            while (r + 1 < n && nums[r] < nums[r + 1])
                r++;
            int len = r - l + 1;

            // if breaks earlier then check again for second segment
            r++;
            l = r;        // moving left pointer to start of second segment
            if (l >= n) { // CHANGED: Added a check to safely exit if there's no
                          // second subarray.
                return max(ans,len/2);
            }
            while (r + 1 < n && nums[r] < nums[r + 1])
                r++;
            int nextlen = r - l + 1;
            int current_score;
            minK = min(nextlen, len);
            maxK = max(nextlen, len); // min aagya noice now check if
            if (maxK / minK > 1) {
                current_score=maxK / 2;
            } else {
                current_score=minK;
            }
            ans = max(ans, current_score);
        }
        return ans;
    }
};