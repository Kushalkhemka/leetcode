

class Solution {
public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        int n = nums.size();
        int ans = 0;

        long long prefixSum = 0;

        unordered_map<long long, int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];

            if (mp.find(prefixSum - k) != mp.end()) {
                int leftIdx = mp[prefixSum - k];
                ans = max(ans, i - leftIdx);
            }

            // Store only the earliest occurrence.
            if (mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }

        return ans;
    }
};