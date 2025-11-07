class Solution {
public:
    bool can_split(vector<int> &nums,int k,int target_sum){
        //check for the subarray 
        int subarrayCount=1;int sumSoFar=0;
        for(int i=0;  i<nums.size();){
            if(nums[i]>target_sum) return false;
            if(sumSoFar+nums[i]<=target_sum){
                sumSoFar+=nums[i];
                i++;
            }
            else{
                subarrayCount++;
                sumSoFar=nums[i];
                i++;
            }
        }
        return subarrayCount<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        //ezy hi toh h hard kyu h then - 
        int lo=*std::min_element(nums.begin(),nums.end());
        int sum=0;
        for(int i=0; i<nums.size();i++){
            sum+=nums[i];
        }
        int hi=sum; int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(can_split(nums,k,mid)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        
        }
        return ans;
    }
};