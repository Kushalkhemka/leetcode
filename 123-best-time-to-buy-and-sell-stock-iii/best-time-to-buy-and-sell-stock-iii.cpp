

class Solution {
   public:
    int fn(int idx, bool flg, int cnt, const vector<int>& arr, const int n,
           vector<vector<vector<int>>>& dp) {
        // 1->already bought 1 share holding -> either do nothing, or sell
        // 0->either buy or skip idx
        if (idx == n) {
            return 0;
        }
        if(flg==0 && cnt==0) return 0;
        if (dp[idx][flg][cnt] != -1) return dp[idx][flg][cnt];
        int nothing = fn(idx + 1, flg, cnt, arr, n, dp);
        int something = 0;
        if (flg) {
            // sell
            something = arr[idx] + fn(idx + 1, 0, cnt, arr, n, dp);
        } else {
            // buy
            if (cnt > 0)
                something = -arr[idx] + fn(idx + 1, 1, cnt - 1, arr, n, dp);
        }
        return dp[idx][flg][cnt] = max(nothing, something);
    }
    int maxProfit(const vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    
        return fn(0, 0, 2, arr, n, dp);
    }
};