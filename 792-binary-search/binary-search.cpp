class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;int hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2; // to prevent overflow of addition of two large int           
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return -1;
    }
};