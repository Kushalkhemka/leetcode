class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;int sum=0;
        for(int num:nums){
            sum=(2*sum)%5+num;
            if(sum%5==0) result.emplace_back(true);
            else result.emplace_back(false);
        }
        return result;
    }
};