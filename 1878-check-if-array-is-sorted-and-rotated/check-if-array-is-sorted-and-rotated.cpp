class Solution {
public:
    bool check(vector<int>& nums) {
        //linear complexity chahie hme
        int ij=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%nums.size()]){
                ij++;
               
            }
            
        }
        if(ij>=2) {
            return false;
        }
        else return true;

    }
};