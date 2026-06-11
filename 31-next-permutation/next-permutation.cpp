class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //first find the break point
        int n=nums.size(); int i=n-1;
        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }
            //i points to the breakpoint
            //now on pos i-1 put the smallest element which is just greater than nums[i-1]
            
    
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j=n-1;
        while(nums[j]<=nums[i-1]){
            j--;
        }
    
        //we ensured of just greater because of sorted order of suffix
        swap(nums[j],nums[i-1]);
        //now sort ahead of i
        sort(nums.begin()+i,nums.end());
    }
};