class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int noOfTimesRepeated = nums.size() / 2;
        unordered_map<int, int> freqMap;

        for (int i = 0; i < nums.size(); i++) {
           
            freqMap[nums[i]]++;  
        }

        for (auto freq : freqMap) {
            if (freq.second == noOfTimesRepeated) {
                return freq.first;
            }
        }

        return -1;
    }
};
