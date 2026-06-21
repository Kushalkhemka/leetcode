
class Solution {
public:
    bool isNStraightHand( vector<int>& nums, const int k) {
        if (nums.size() % k != 0)
            return false;

        map<int, int> freqMap;

        for (int &x : nums) {
            freqMap[x]++;
        }

        for (auto& [val, fVal] : freqMap) {
            if (fVal > 0) {
                int groups = fVal;

                for (int i = val; i < val + k; i++) {
                    auto it = freqMap.find(i);

                    if (it != freqMap.end() && it->second >= groups) {
                        it->second -= groups;
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};