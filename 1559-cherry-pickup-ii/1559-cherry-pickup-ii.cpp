
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
        vector<vector<int>> front(m, vector<int>(m, -1));
        vector<vector<int>> curr(m, vector<int>(m, -1));

        // base case
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    front[j1][j2] = matrix[n - 1][j1];
                else
                    front[j1][j2] = matrix[n - 1][j1] + matrix[n - 1][j2];
            }
        }
        // n-1 plane is already filled so move to n-2 to 0
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = INT_MIN;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            // for one dj1, dj2 have 3 possible moves
                            int value = 0;
                            if (j1 == j2)
                                value = matrix[i][j1];
                            // only one out of two will be executed
                            else
                                value = matrix[i][j2] + matrix[i][j1];
                            if (j1 + dj1 >= 0 && j1 + dj1 < m &&
                                j2 + dj2 >= 0 && j2 + dj2 < m) {
                                value += front[j1 + dj1][j2 + dj2];
                            } else
                                value += -1e8;
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }

        return curr[0][m - 1];
    }
};