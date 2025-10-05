class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //bro make a hashman of freq count, traverse again in the hashmap return the key with highest value
        int n=nums.size();
        unordered_map<int,int> hashmap;
        for(int i=0;i<n;i++){
            if(hashmap.find(nums[i])==hashmap.end()){
                hashmap.insert({nums[i],1});
            }
            else{
                hashmap[nums[i]]+=1;
            }
        }
        int maxfreq=0; int maxElement=-1;
        for (const auto& [key, val] : hashmap) {
            if(val>maxfreq){
                maxfreq=val;
                maxElement=key;
            }
            
        }
        return maxElement;
    }
    
};