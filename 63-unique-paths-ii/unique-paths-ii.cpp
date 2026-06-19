
class Solution {
public:
    int fn(int i,int j,int m,int n,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
        if(i>m-1 || j>n-1 || i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;//return 1 to count this valid path which reached this cell
         //handle out of bound indexes
        
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=fn(i-1,j,m,n,dp,obstacleGrid)+fn(i,j-1,m,n,dp,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fn(m-1,n-1,m,n,dp,obstacleGrid);
    }
};