class Solution {
public:
    int cnt=0;
    void fn(int idx, const vector<int>&nums, int target){
        if(idx<0) {
            if(target==0) cnt++;
            return;
        } 

        //take +
        fn(idx-1,nums,target-nums[idx]);

        //take -
        fn(idx-1,nums,target+nums[idx]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        fn(nums.size()-1,nums,target);
        return cnt;
    }
};