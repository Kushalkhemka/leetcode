class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int max_sum=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     int maxtemp=0; 
        //     for(int j=i;j<nums.size();j++){
        //         maxtemp+=nums[j];
        //         max_sum=max(max_sum,maxtemp);
                
        //     }
            
        // }
        // return max_sum;
        int max_sum=INT_MIN;
        int current_sum=0;
        for(int i=0;i<nums.size();i++){
            current_sum+=nums[i];
            if(max_sum<=current_sum){
                max_sum=current_sum;
            }
            if(current_sum<0){
                current_sum=0;
            }
            
        }
        return max_sum;


        
    }
};