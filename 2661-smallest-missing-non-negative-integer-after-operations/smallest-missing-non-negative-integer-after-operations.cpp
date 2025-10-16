class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        //let make the hashmap
        // unordered_map<int,int> hashmap;                        // CHANGED: remove unused per-value map (causes TLE)
        // int maxVal=INT_MIN;                                    // CHANGED: no longer needed

        // CHANGED: use residue-frequency buckets of size 'value'
        vector<long long> freq(value, 0);                        // CHANGED: freq[r] = count of numbers with residue r mod 'value'

        for (int i = 0; i < (int)nums.size(); i++) {
            // if(hashmap.find(nums[i])==hashmap.end()){         // CHANGED: replaced with residue bucketing
            //     hashmap.insert({nums[i],1});
            // }
            // else{
            //     hashmap[nums[i]]++;
            // }
            // maxVal=max(maxVal,nums[i]);

            int r = ((nums[i] % value) + value) % value;         // CHANGED: normalize negatives to [0, value)
            freq[r]++;                                           // CHANGED: count by residue
        }

        //freq map is created above now use modular proprty
        //now do the shit loops
        int i = 0;
        // while(i<=nums.size()){                                 // CHANGED: we may need to go beyond n; loop until return
        while (true) {                                           // CHANGED: infinite loop; returns when matching residue bucket is empty
            int r = i % value;                                   // CHANGED: residue for current candidate 'i'
            if (freq[r] > 0) {                                   // CHANGED: if a number exists to "occupy" this 'i', consume it
                freq[r]--;                                       // CHANGED
                i++;                                             // CHANGED
            } else {
                //exist ni krta toh iterate maaro hashmap ko 
                // int flag=0;                                   // CHANGED: no scanning; bucket empty means 'i' is the mex
                // for(auto &[val,freq]:hashmap){
                //     if(val%value==i%value && freq>0){
                //         flag=1;
                //         hashmap[val]--;
                //         i++;
                //     }
                // }
                // if(!flag){
                //     return i;
                // }
                return i;                                        // CHANGED: mex found
            }
        }

        // return i;                                              // CHANGED: unreachable now
    }
};
