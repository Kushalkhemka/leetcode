class Solution {
public:
    vector<long long> dp; 

    long long fn(const vector<int>& nums, int currSum, int target) {
        if (currSum == target) {
            return 1; 
        }

        if (currSum > target) {
            return 0; 
        }

        if (dp[currSum] != -1) {
            return dp[currSum]; 
        }

        long long ways = 0; 
       
        for (int i = 0; i < nums.size(); i++) {
            if (currSum + nums[i] <= target) {
                ways += fn(nums, currSum + nums[i], target); 
            }
            else break; 
        }

        return dp[currSum] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dp.assign(target + 1, -1); 
        return (int)fn(nums, 0, target); 
    }
};