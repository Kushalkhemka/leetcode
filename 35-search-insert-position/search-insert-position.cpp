class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //let's apply binary search beta
        int lo=0; int high =nums.size()-1; int lastidx=0;
        while(lo<=high){
            int mid=lo+(high-lo)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(target<nums[mid]){
                high=mid-1;
            }
            else{
                //target on right side
                lo=mid+1;
            }
            lastidx=min(mid,high);
        }
        //if running this code means target not found so correct index of the target will be the last mid i guess
        
            return lastidx+1;
        
        // return -1; //dummy return statement; 
    }
};