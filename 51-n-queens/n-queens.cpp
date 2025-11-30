class Solution {
public:
    bool isSafe(int row,int col,vector<string>&board,int n){
        //dekho ki isSafe in upper diagonal, straight in the row, lower diagonal;
        int originalRow=row; int originalCol=col;
        //1st condition check in the current row
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        //2nd condition check in the principal diagonal
        row=originalRow; col=originalCol;
        while(row>=0&& col>=0){
            if(board[row][col]=='Q') return false;
            row--;col--;
        }
        //3rd condition check in the other diagonal
        row=originalRow; col=originalCol;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;col--;
        }
        return true;
        
    }
    void solve(int col, vector<string>&board, vector<vector<string>>&ans,int n){
        if(col==n){
            //base case reached enjoy terminate i mean
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                //pop out for the backtrack
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        //solve(col,board,ans,n(opt))
        solve(0,board,ans,n);
        return ans;
    }
};