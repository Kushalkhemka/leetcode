class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        vector<int> prev(m+1,0),curr(m+1,0);
        //----BASE CASE---//
        for (int j = 0; j <= m; j++) {
            prev[j] = j;
        }
        //----BASE CASE---//

        for (int i = 1; i <= n; i++) {
            curr[0]=i;
            for (int j = 1; j <= m; j++) {
                // match
                
                if (word1[i-1] == word2[j-1])
                    curr[j] = 0 + prev[j - 1];
                // not match
                // fn(i,j-1) -> insert
                // fn(i-1,j) -> delete
                // fn(i-1,j-1) -> replace
                else curr[j] =
                    1 + min(curr[j - 1], min(prev[j],prev[j - 1]));
            }
            prev=curr;
        }

        return prev[m];
    }
};