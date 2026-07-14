

class Solution {
public:
    bool isSafe(int r, int c, vector<string>& board) {
        int n = board.size(); // determine number of rows
        int i = r;
        int j = c;
        // check for the left side of same row
        while (j >= 0) {
            if (board[r][j] == 'Q')
                return false;
            j--;
        }
        i = r;
        j = c; // restoring back val for next check
        // check for principal diagonal towards top left
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        i = r;
        j = c;
        // check for anti diagonal
        while (i < n && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }

        return true;
    }

    void fn(int col, int n, vector<vector<string>>& ans,
            vector<string>& board) {
        // row col
        if (col == n) {
            // put the ans back to the ans
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            // try putting in all rows for all cols
            if (isSafe(i, col, board)) {

                // put it
                board[i][col] = 'Q'; // changing single char of the string at
                                     // rth idx in vector board

                fn(col + 1, n, ans, board);

                board[i][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n); // 4 strings in a vector
        // string bharo plan
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i].push_back('.');
            }
        }
        fn(0, n, ans, board);
        return ans;
    }
};