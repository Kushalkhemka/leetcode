

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> dp(n, 1);
        // from idx 0 to n-1 and prev 0 to n-1
        vector<int> hash(n);
        vector<int> ans;
        int maxi = 1;
        int lastIndex = 0;
        for (int idx = 0; idx < n; idx++) {
            hash[idx] = idx;
            for (int prev = 0; prev < idx; prev++) {
                if (arr[idx] % arr[prev] == 0 && dp[prev] + 1 > dp[idx]) {
                    // update the dp idx
                    dp[idx] = dp[prev] + 1; // hmm update its hsh also
                    hash[idx] = prev;
                }
            }
            // after the loop ends now we have to see
            if (maxi < dp[idx]) {
                // update the maxi
                maxi = dp[idx];
                lastIndex = idx;
            }
        }

        while (
            hash[lastIndex] !=
            lastIndex) { // justg like dsu parent finding the one with same
                         // hash[lastIndex] at same index is the one which ends
            // update the last index to
            ans.push_back(arr[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        ans.push_back(arr[lastIndex]);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
