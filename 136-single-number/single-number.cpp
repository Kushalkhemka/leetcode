class Solution {
public:
    // int singleNumber(vector<int>& nums) {
    //     //hashmap banao enjoy kro jiski freq 1 h uska maja - 
    //     unordered_map<int,int> hashmap;
        
    //     for(int i=0;i<nums.size();i++){
    //         if(hashmap.find(nums[i])==hashmap.end()){
    //             hashmap.insert({nums[i],1});
    //         }
    //         else{
    //             //already hai
    //             hashmap[nums[i]]+=1;
    //         }
    //     }

    //     for(auto &[num,freq] : hashmap){
    //         if(freq==1){
    //             return num;
    //         }
    //     }
    //     return 0;
    // }   

    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int num : nums) {
            x ^= num; // All duplicates cancel; only the unique remains
        }
        return x; 
    }   

    
};