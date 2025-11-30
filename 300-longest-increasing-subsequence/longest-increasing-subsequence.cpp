class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int>next(n+1,0),curr(n+1,0);
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prev = idx - 1; prev >= -1; prev--) {       

                int not_take = next[prev + 1];            

                int take = INT_MIN;
                if (prev == -1 || nums[prev] < nums[idx]) {
                    take = 1 + next[idx + 1];             
                }

                curr[prev + 1] = max(take, not_take);        
            }
            next=curr;
        }

        return curr[-1+1];    
    }
};
