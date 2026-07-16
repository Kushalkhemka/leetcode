

class Solution {
public:
    bool isPredecessor(string& smaller, string& bigger) {
        if (bigger.size() != smaller.size() + 1)
            return false;

        int i = 0; // smaller
        int j = 0; // bigger

        while (i < smaller.size() && j < bigger.size()) {
            if (smaller[i] == bigger[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        return i == smaller.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        int n = words.size();
        vector<int> dp(n, 1);
        // from idx 0 to n-1 and prev 0 to n-1
        int maxi = 1;
        for (int idx = 0; idx < n; idx++) {
            int prev = idx - 1;
            while (prev >= 0 &&
                   (words[idx].length() - words[prev].length()) <= 1) {
                if (isPredecessor(words[prev], words[idx]) &&
                    dp[prev] + 1 > dp[idx]) {
                    // update the dp idx
                    dp[idx] = dp[prev] + 1; // hmm update its hsh also
                }
                prev--;
            }
            // after the loop ends now we have to see
            if (maxi < dp[idx]) {
                // update the maxi
                maxi = dp[idx];
            }
        }
        return maxi;
    }
};
