#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9+7;

        unordered_map<long long, long long> rightCount;
        unordered_map<long long, long long> leftCount;

        long long ans = 0;
        int n = nums.size();

        for (int x : nums) {
            rightCount[x]++;
        }

        for (int j = 0; j < n; ++j) {
            long long x = nums[j];
            rightCount[x]--;

            long long target = 2LL * x;

            long long left  = leftCount[target];
            long long right = rightCount[target];

            ans = (ans + (left * right) % MOD) % MOD;

            leftCount[x]++;
        }

        return static_cast<int>(ans % MOD);
    }
};
