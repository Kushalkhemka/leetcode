
class Solution {
public:
    int fn(int idx1, int idx2, string& str1, string& str2,
           vector<vector<int>>& dp) {
        if (idx1 < 0 || idx2 < 0) {
            return 0;
        }
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if (str1[idx1] == str2[idx2]) {
            // both same then call
            return dp[idx1][idx2] = fn(idx1 - 1, idx2 - 1, str1, str2, dp) + 1;
        }
        return dp[idx1][idx2] = max(fn(idx1 - 1, idx2, str1, str2, dp),
                                    fn(idx1, idx2 - 1, str1, str2, dp));
    }
    int lcs(string& str1, string& str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        vector<vector<int>> dp(n1, vector(n2, -1));
        return fn(n1 - 1, n2 - 1, str1, str2, dp);
    }

    int longestPalinSubseq(string& s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return lcs(s, rev);
    }
    int minInsertions(string& s) {
        return (s.length() - longestPalinSubseq(s));
    }
};
