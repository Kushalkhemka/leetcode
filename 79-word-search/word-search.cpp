class Solution {
public:

    bool fn(vector<vector<char> >& board, string word, int idx, int i, int j) {
        char x = board[i][j];

        if (x == '#' || x != word[idx]) {
            return false;
        }

        if (idx == word.size() - 1) { 
            return true;
        }

        board[i][j] = '#'; 
        bool ans = false;

        // top
        if (i - 1 >= 0) { 
            ans |= fn(board, word, idx + 1, i - 1, j);
        }

        // bottom
        if (i + 1 < board.size()) {
            ans |= fn(board, word, idx + 1, i + 1, j);
        }

        // left
        if (j - 1 >= 0) { 
            ans |= fn(board, word, idx + 1, i, j - 1);
        }

        // right
        if (j + 1 < board[0].size()) {
            ans |= fn(board, word, idx + 1, i, j + 1);
        }

        board[i][j] = x; 

        return ans;
    }

    bool exist(vector<vector<char> >& board, string word) {
        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == word[0]) {
                    if (fn(board, word, 0, i, j)) { 
                        return true;
                    }
                }
            }
        }

        return false; 
    }
};