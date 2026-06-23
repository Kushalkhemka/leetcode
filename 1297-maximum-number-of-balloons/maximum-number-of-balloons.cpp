class Solution {
public:
    int maxNumberOfBalloons(string& text) {
        unordered_map<int, int> freqMap;
        for (auto& c : text) {
            freqMap[c]++;
        }
        vector<char> arr = {'b', 'a', 'l', 'l', 'o', 'o', 'n'};
        int ans = 1e9;
        if (freqMap['o'] > 0)
            freqMap['o'] /= 2;
        if (freqMap['l'] > 0)
            freqMap['l'] /= 2;
        for (int i = 0; i < arr.size(); i++) {
            ans = min(ans, freqMap[arr[i]]);
        }
        return ans;
    }
};