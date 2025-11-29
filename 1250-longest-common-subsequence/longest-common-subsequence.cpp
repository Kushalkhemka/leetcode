class Solution {
public:
    int fn(int idx1,int idx2, string &text1,string &text2,vector<vector<int>> &dp){
        if(idx1<0 || idx2<0){
            return 0;
        }
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(text1[idx1]==text2[idx2]){
            return dp[idx1][idx2]=1+fn(idx1-1,idx2-1,text1,text2,dp);
        }
        else{
            return dp[idx1][idx2]=0+max(fn(idx1-1,idx2,text1,text2,dp),fn(idx1,idx2-1,text1,text2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        //dp lagao yeeeee
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return fn(text1.length()-1,text2.length()-1,text1,text2,dp);
    }
};