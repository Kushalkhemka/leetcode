#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1'000'000'007;

        int n = nums.size();

        // Step 1: Collect all values we will ever need:
        // We need nums[j] and 2 * nums[j]
        vector<long long> vals;
        vals.reserve(2 * n);

        for (long long x : nums) {
            vals.push_back(x);
            vals.push_back(2LL * x);
        }

        // Step 2: Coordinate compression
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto getIndex = [&](long long v) {
            return int(lower_bound(vals.begin(), vals.end(), v) - vals.begin());
        };

        int K = vals.size();

        // Step 3: Replace unordered_map with fixed-size vectors
        vector<long long> leftCount(K, 0), rightCount(K, 0);

        for (long long x : nums) {
            rightCount[getIndex(x)]++;
        }

        long long ans = 0;

        // Step 4: Sweep j
        for (int j = 0; j < n; ++j) {
            long long x = nums[j];
            int idxX = getIndex(x);
            rightCount[idxX]--;

            long long target = 2LL * x;
            int idxT = getIndex(target);

            long long left = leftCount[idxT];
            long long right = rightCount[idxT];

            ans = (ans + (left * right) % MOD) % MOD;

            leftCount[idxX]++;
        }

        return int(ans);
    }
};
