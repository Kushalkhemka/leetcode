class Solution {
   public:
    vector<vector<int> > ans;
    void fn(const vector<int>& nums, vector<int>& arr, const int k,const int n, int currSum,
            int idx) {
        if (currSum == n) {
            if(arr.size()==k) ans.push_back(arr);
            return;
        }

        if (idx == nums.size() || currSum > n) {
            return;
        }

        // take but infinite possibility so keep same idx until less than k
        if (currSum < n) {
            arr.push_back(nums[idx]);
            fn(nums, arr,k, n, currSum + nums[idx], idx+1);
        }
        // not take
        arr.pop_back();
        fn(nums, arr, k, n, currSum, idx + 1);
    }
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> temp;
        fn(v,temp,k,n,0,0);
        return ans;
    }
};