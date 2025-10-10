class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0; int hi=nums.size()-1;
        while(lo<=hi){
            //means array not sorted
            int mid=lo+(hi-lo)/2;
            if(nums[lo]<=nums[hi]) return nums[lo];
            if(mid>0 && nums[mid-1] > nums[mid]){
                return nums[mid];
            }
            else if(mid<hi && nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            else{
                //decide to go into one
                if(nums[lo]<=nums[mid]) lo=mid+1;
                else hi=mid-1;
            }

        }
        return -1;
    }
};