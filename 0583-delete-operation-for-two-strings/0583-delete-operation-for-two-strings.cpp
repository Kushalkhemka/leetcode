

class Solution {
public:
    // int fn(int idx1, int idx2, string &str1, string &str2,
    //        vector<vector<int>> &dp) {
    //     if (idx1 < 0 || idx2 < 0) {
    //         return 0;
    //     }
    //     if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    //     if (str1[idx1] == str2[idx2]) {
    //         // both same then call
    //         return dp[idx1][idx2] = fn(idx1 - 1, idx2 - 1, str1, str2, dp) +
    //         1;
    //     }
    //     return dp[idx1][idx2] = max(fn(idx1 - 1, idx2, str1, str2, dp),
    //                                 fn(idx1, idx2 - 1, str1, str2, dp));
    // }

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
    int lcs(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        vector<vector<int>> dp(n1, vector(n2, -1));
        return fn(n1 - 1, n2 - 1, str1, str2, dp);
    }

    // pair<int,string> lcs(string str1, string str2) {
    //     int n1 = str1.length();
    //     int n2 = str2.length();
    //     vector<vector<int>> dp(n1+1, vector(n2+1, 0));
    //     // go from 0 to n1-1 and 0 to n2-1

    //     for (int idx1 = 1; idx1 <= n1; idx1++) {
    //         for (int idx2 = 1; idx2 <= n2; idx2++) {
    //             if (str1[idx1-1] == str2[idx2-1]) {
    //                 // both same then call
    //                 dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1] + 1;
    //             }
    //             else dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 -
    //             1]);
    //         }
    //     }
    //     int length=dp[n1][n2];
    //     string ans="";
    //     int i=n1;int j=n2;
    //     while(i>0 && j>0){
    //         if(str1[i-1]==str2[j-1]){
    //             //string last character match
    //             ans.push_back(str1[i-1]);
    //             i--;j--;
    //         }
    //         else if(dp[i-1][j]>dp[i][j-1]){
    //             i--;
    //         }
    //         else{
    //             j--;
    //         }
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return {length,ans};
    // }

    int minDistance(string& str1, string& str2) {
        int l = lcs(str1, str2);
        // now check how many matching
        // get the lcs string

        // check common characters and remove the rest
        int n1 = str1.length();
        int n2 = str2.length();

        int deleteOp = n1 - l;
        int addOp = n2 - l;
        return deleteOp + addOp;
    }
};