class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp lagao yeeeee
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        //------BASE CASE STARTS------//
        // run the loop
        for (int i = 0; i <= n1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= n2; i++) {
            dp[0][i] = 0;
        }
        //------BASE CASE ENDS------//

        //------MAKE LOOPS FOR CHANGING PARAMS IDX1 IDX2 STEP2------//
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                // f(idx1, IDX2) -> f(i,j)
                //------COPY RECURRENCE STEP3------//
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
                }
                //------COPY RECURRENCE STEP3------//
            }
        }
        //------LOOP ENDS------//
        return dp[n1][n2];
    }
};