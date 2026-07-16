

class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> freq(n, 1);
        // from idx 0 to n-1 and prev 0 to n-1
        int maxi = 1;
        for (int idx = 1; idx < n; idx++) {
            for (int prev = 0; prev < idx; prev++) {
                if (arr[prev] < arr[idx]) {
                    // update the dp idx
                    if (dp[prev] + 1 > dp[idx]) {
                        dp[idx] = dp[prev] + 1;
                        freq[idx] = freq[prev];
                    } else if (dp[prev] + 1 == dp[idx]) {
                        freq[idx] += freq[prev];
                    }
                }
            }
            // after the loop ends now we have to see
            if (maxi < dp[idx]) {
                // update the maxi
                maxi = dp[idx];
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                cnt += freq[i];
            }
        }
        return cnt;
    }
};
