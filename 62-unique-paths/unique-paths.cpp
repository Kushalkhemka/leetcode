class Solution {
public:
    int fn(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;//return 1 to count this valid path which reached this cell
        if(i>m-1 || j>n-1 || i<0 || j<0) return 0; //handle out of bound indexes
        if(dp[i][j]!=-1) return dp[i][j];
        int up=fn(i-1,j,m,n,dp);
        int left=fn(i,j-1,m,n,dp);
        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fn(m-1,n-1,m,n,dp);
    }
};