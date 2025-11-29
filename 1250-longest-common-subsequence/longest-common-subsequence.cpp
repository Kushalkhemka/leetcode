class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp lagao yeeeee
        int n1 = text1.length();
        int n2 = text2.length();
        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        vector<int> prev(n2+1,0),curr(n2+1,0); //prev=dp[i-1] replace and curr=dp[i]
        //------BASE CASE STARTS------//
        // run the loop
        for (int i = 0; i <= n2; i++) {
           prev[i] = 0;
        }
        //------BASE CASE ENDS------//

        //------MAKE LOOPS FOR CHANGING PARAMS IDX1 IDX2 STEP2------//
        for (int i = 1; i <= n1; i++) { //i tied to n1
            for (int j = 1; j <= n2; j++) { //j tied to n2
                // f(idx1, IDX2) -> f(i,j)
                //------COPY RECURRENCE STEP3------//
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = 0 + max(prev[j], curr[j - 1]);
                }
                //------COPY RECURRENCE STEP3------//
            }
            prev = curr;

        }
        //------LOOP ENDS------//
        return prev[n2];
    }
};