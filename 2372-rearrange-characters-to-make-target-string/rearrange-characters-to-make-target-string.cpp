class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<int, int> freqMap;
        unordered_map<int, int> mp;
        for (auto& c : s) {
            freqMap[c]++;
        }

        for (auto& c : target) {
            mp[c]++;
        }
        int ans = 1e9;
        for(auto&[val,freq]:mp){
            if(freqMap.find(val)!=freqMap.end()){
                ans= min(ans,freqMap[val]/freq);
            }
            else{
                ans=0;
            }
        }
        return ans;
    }
};