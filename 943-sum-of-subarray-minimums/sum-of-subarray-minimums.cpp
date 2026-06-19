class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;

        vector<int> pse(n, -1);
        vector<int> nse(n, n);

        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {
                s.push(i);
                continue;
            }

            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }

            if (s.empty()) {
                s.push(i);
            } else {
                nse[i] = s.top();
                s.push(i);
            }
        }

        while (!s.empty()) {
            s.pop();
        }

        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                s.push(i);
                continue;
            }

            while (!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }

            if (s.empty()) {
                s.push(i);
            } else {
                pse[i] = s.top();
                s.push(i);
            }
        }
        // why n-> including the i so n-i gives the number of element ahead of
        // it in whihc it is minimum that start from i so [3,1,2,4] , here for
        // "2" n=4, so it got 2 subarrays [2,4] and the [2] for pse it is i-(-1)
        // if no pse, then i+1 so it incldues the i, here [2] only one subarray,
        // 1*2=2 subarray
        long long sum = 0;
        int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int a = (1LL * (i - pse[i]) * nums[i]) % MOD;
            sum = (sum + (1LL * (nse[i] - i) * a) % MOD) % MOD;
        }

        return (int)sum;
    }
};