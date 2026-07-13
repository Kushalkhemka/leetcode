class Solution {
public:
    vector<unordered_set<char>> subgrids;
    vector<unordered_set<char>> rows;
    vector<unordered_set<char>> cols;
    int n;
    bool isSafe(int r, int c, char num) {
        if (rows[r].find(num) != rows[r].end())
            return false;
        if (cols[c].find(num) != cols[c].end())
            return false;
        int subgridNo = (r / 3) * (n / 3) + (c / 3);
        if (subgrids[subgridNo].find(num) != subgrids[subgridNo].end())
            return false;

        rows[r].insert(num);
        cols[c].insert(num);
        subgrids[subgridNo].insert(num);
        return true; // else safe
    }

    void erase(int r, int c, char num) {
        int subgridNo = (r / 3) * (n / 3) + (c / 3);

        rows[r].erase(num);
        cols[c].erase(num);
        subgrids[subgridNo].erase(num);
        return; // else safe
    }

    bool fn(vector<vector<char>>& board) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    // we need to fill in
                    for (char k = '1'; k <= '9'; k++) {
                        // check if its safe to fill if safe then fill the next
                        if (isSafe(i, j, k)) {
                            // yes it is safe to place this number so add this
                            // into the all three
                            board[i][j] = k;

                            if (fn(board))
                                return true;
                            else {
                                erase(i, j, k);
                                board[i][j] =
                                    '.'; // we will try to fill something else
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // your code goes here
        n = board.size();
        int howManySubgrids = n / 3;

        subgrids.resize(howManySubgrids * howManySubgrids);
        rows.resize(n);
        cols.resize(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    // not empty
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    int subgridNo = (i / 3) * (n / 3) + (j / 3);
                    subgrids[subgridNo].insert(board[i][j]);
                }
            }
        }

        // PREFILLING DONE
        fn(board);
    }
};