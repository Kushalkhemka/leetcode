class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size(); int threshold=n/3;
        unordered_map<int,int> hashmap;
        for(int i=0;i<n;i++){
            if(hashmap.find(nums[i])==hashmap.end()){
                hashmap.insert({nums[i],1});
            }
            else{
                hashmap[nums[i]]+=1;
            }
        }
       vector<int> E;
        for (const auto& [key, val] : hashmap) {
            if(val>threshold){
                E.emplace_back(key);
            }
            
        }
        return E;
    }
    
};