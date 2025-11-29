class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(); int T=amount;
        
        vector<int> prev(T+1,1e9);
        prev[0] = 0;
        for (int t = 0; t <= T; t++) {
            if (t % coins[0] == 0)
                prev[t] = t / coins[0];
        }
        
        for (int idx = 1; idx < n; idx++) {
            for (int t = 0; t <= T; t++) {
                int not_take = prev[t];
                int take = 1e9;
                if (coins[idx] <= t)
                    take = 1 + prev[t - coins[idx]];

                prev[t] = min(take, not_take);
            }
        }

        return prev[T] >= 1e9 ? -1 : prev[T];
    }
};
