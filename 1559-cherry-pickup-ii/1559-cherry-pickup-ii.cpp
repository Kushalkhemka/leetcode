
class Solution {
public:
    int fn(int i, int j1, int j2, int r, int c, vector<vector<int>>& matrix,
           vector<vector<vector<int>>>& dp) {
        // oob case
        if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) {
            return -1e9;
        }
        // base case
        if (i == r - 1) {
            // last row pe pahuch gye
            if (j1 == j2)
                return matrix[i][j1];
            else
                return matrix[i][j1] + matrix[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        // traverse all the possible cases since it is joint recursion so for
        // one move of second robot, first could have 3 possible moves so 3*3 =
        // 9 total moves dj=-1,0,1
        int maxi = INT_MIN;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                // for one dj1, dj2 have 3 possible moves
                if (j1 == j2)
                    maxi = max(maxi,
                               fn(i + 1, j1 + dj1, j2 + dj2, r, c, matrix, dp) +
                                   matrix[i][j1]);
                // only one out of two will be executed
                else
                    maxi = max(maxi,
                               fn(i + 1, j1 + dj1, j2 + dj2, r, c, matrix, dp) +
                                   matrix[i][j2] + matrix[i][j1]);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));

        return fn(0, 0, m - 1, n, m, matrix, dp);
    }
};