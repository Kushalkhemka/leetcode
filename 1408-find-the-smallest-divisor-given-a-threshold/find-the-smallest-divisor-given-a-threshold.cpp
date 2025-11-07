class Solution {
public:
    int sumOfDivision(vector<int>& nums,int divisor){
        //ceil division
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(nums[i]+divisor-1)/divisor;
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1;int hi=*std::max_element(nums.begin(), nums.end());
        int ans=1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(sumOfDivision(nums,mid)>threshold){
                lo=mid+1;
            }
            else{ 
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;
    }
};