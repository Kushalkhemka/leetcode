class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> freqmap;
        for(int i:nums){
            freqmap[i]++; //increasing the freq
        }
        int sum=0;
        for(auto &[val,freq]:freqmap){
            if(freq%k==0){
                sum+=val*freq; 
            }
        }
        return sum;
    }
};