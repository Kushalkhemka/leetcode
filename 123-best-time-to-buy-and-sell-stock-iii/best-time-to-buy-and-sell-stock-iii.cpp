

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxCap = 2;
        int n=arr.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(maxCap + 1, 0))
        );

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int flg = 0; flg <= 1; flg++) {
                for (int cap = 1; cap <= maxCap; cap++) {

                    int nothing = dp[idx + 1][flg][cap];
                    int something = 0;

                    if (flg == 0) {
                        // buy
                        something = -arr[idx] + dp[idx + 1][1][cap]; //  cap same because transaction not completed yet
                    } 
                    else {
                        // sell
                        something = arr[idx] + dp[idx + 1][0][cap - 1]; //  cap decreases after sell because transaction completes
                    }

                    dp[idx][flg][cap] = max(nothing, something);
                }
            }
        }

        return dp[0][0][2];
    }
};