class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<long long> dp(n, 0);
        vector<int> st;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.back()]) {
                st.pop_back();
            }

            if (st.empty()) {
                dp[i] = 1LL * (i + 1) * arr[i];
            } else {
                int j = st.back();
                dp[i] = dp[j] + 1LL * (i - j) * arr[i];
            }

            dp[i] %= MOD;
            ans = (ans + dp[i]) % MOD;

            st.push_back(i);
        }

        return (int)ans;
    }
};