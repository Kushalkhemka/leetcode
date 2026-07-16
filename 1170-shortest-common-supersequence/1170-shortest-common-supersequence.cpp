class Solution {
public:
    string lcs(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        vector<vector<int>> dp(n1 + 1, vector(n2 + 1, 0));
        // go from 0 to n1-1 and 0 to n2-1

        for (int idx1 = 1; idx1 <= n1; idx1++) {
            for (int idx2 = 1; idx2 <= n2; idx2++) {
                if (str1[idx1 - 1] == str2[idx2 - 1]) {
                    // both same then call
                    dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1] + 1;
                } else
                    dp[idx1][idx2] =
                        max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
            }
        }
        int length = dp[n1][n2];
        string ans = "";
        int i = n1;
        int j = n2;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
            } else {
                ans.push_back(str2[j - 1]);
                j--;
            }
        }

        while (i > 0) {
            ans.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            ans.push_back(str2[j - 1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string& str1, string& str2) {
        return lcs(str1, str2);
    }
};