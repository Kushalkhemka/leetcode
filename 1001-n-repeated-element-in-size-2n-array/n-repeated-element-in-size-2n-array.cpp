class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int, int> freqMap;

        for (int x : nums) {
            if (++freqMap[x] == n) return x; // CHANGED: early exit
        }
        return -1;
    }
};
