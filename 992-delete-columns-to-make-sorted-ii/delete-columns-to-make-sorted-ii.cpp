class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = (int)strs.size();
        int m = (int)strs[0].size();
        int ans = 0;

        vector<bool> locked(n - 1, false);
        int lockedCount = 0;                          

        for (int col = 0; col < m && lockedCount < n - 1; col++) {
            for (int i = 0; i < n - 1; i++) {
                if (locked[i]) continue;
                if (strs[i][col] > strs[i + 1][col]) {
                    ans++;
                    goto next_col;                      
                }
            }

            for (int i = 0; i < n - 1; i++) {
                if (!locked[i] && strs[i][col] < strs[i + 1][col]) {
                    locked[i] = true;
                    lockedCount++;                      
                }
            }

        next_col:
            continue;
        }
        return ans;
    }
};
