class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> freqMap;
        for(int x:nums){
            freqMap[x]++;
        }

        for(auto [val,fVal]:freqMap){
            if(fVal>0){
                for(int i=val;i<val+k;i++){
                    if(freqMap[i]>=fVal) freqMap[i]-=fVal;
                    else return false;
                }
            }
        }
        return true;
    }
};