

class Solution {
public:
    static const int MOD = 1e9 + 7;
    int fn(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (j < 0)
            return 1; // t gets exhausted
        if (i < 0) {
            // means s gets exhausted
            return 0;
        }

        // now i,j ke lie try krna h
        if (dp[i][j] != -1)
            return dp[i][j];
        int way1 = 0;
        int way2 = 0;
        if (s[i] == t[j]) {
            // it matches then
            way1 = fn(i - 1, j, s, t,
                      dp) // it means we want more number of char from s
                   + fn(i - 1, j - 1, s, t, dp) %
                         MOD; // we got the one and ab yhi se manke chalo
        } else {
            way2 = fn(i - 1, j, s, t, dp) %
                   MOD; // no way we ned to reduce search space of s to get last
                        // char matched first of t
        }
        return dp[i][j] = (way1 + way2) % MOD; // count number of ways
    }
    int numDistinct(string& s, string& t) {
        // s is bigger string and t is smaller string
        int s1 = s.size();
        int t1 = t.size();
        vector<vector<int>> dp(s1, vector<int>(t1, -1));
        // i-> s and j->t
        return fn(s1 - 1, t1 - 1, s, t, dp);
    }
};