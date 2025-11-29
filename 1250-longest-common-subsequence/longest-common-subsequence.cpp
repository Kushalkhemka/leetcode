class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        vector<int> dp(n2 + 1, 0);    // changed: use single array

        for (int i = 1; i <= n1; i++) {
            int diag = 0;            // new: dp[i-1][j-1]

            for (int j = 1; j <= n2; j++) {

                int temp = dp[j];    // new: store dp[i-1][j] before overwriting

                if (text1[i-1] == text2[j-1]) {
                    dp[j] = 1 + diag;       // changed: use diag instead of prev[j-1]
                } else {
                    dp[j] = max(dp[j], dp[j-1]);
                }

                diag = temp;         // new: shift diagonal for next j
            }
        }

        return dp[n2];
    }
};
