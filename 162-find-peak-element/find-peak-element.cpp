class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo=0; int hi=nums.size()-1; 
      
        while(lo<hi){
            int mid=lo+(hi-lo)/2; 
            if(mid<nums.size() && nums[mid]>nums[mid+1]){
                //mid could be itself a peak or peak is on left side 
                hi=mid;
            }
            else{
                //mid is less than mid+1
                lo=mid+1;
            }
        }
        return lo;
    }
};