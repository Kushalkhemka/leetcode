class Solution {
public:
    int fn(int i, int j,string &word1, string &word2,vector<vector<int>> &dp){
        //i->S1 //j->S2
        if(i<0){
            //target string exhausted meaning need to add the pending chars from given string word2
            return j+1;
        }
        if(j<0){
            //source string exhausted so need to delete from the target string word1
            return i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        // match
        if(word1[i]==word2[j]) return dp[i][j]=0+fn(i-1,j-1,word1,word2,dp);
        //not match
            //fn(i,j-1) -> insert
            //fn(i-1,j) -> delete
            //fn(i-1,j-1) -> replace
            return dp[i][j]=1+min(fn(i,j-1,word1,word2,dp),min(fn(i-1,j,word1,word2,dp),fn(i-1,j-1,word1,word2,dp)));
        
    }
    int minDistance(string word1, string word2) {
        
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fn(n-1,m-1,word1,word2,dp);
    }
};