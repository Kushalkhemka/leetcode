class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> pse(n, -1);
        vector<int> pge(n, -1);
        vector<int> nse(n, n);
        vector<int> nge(n, n);
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

        while (!s.empty()) {
            s.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {
                s.push(i);
                continue;
            }

            while (!s.empty() && nums[s.top()] <= nums[i]) {
                s.pop();
            }

            if (s.empty()) {
                s.push(i);
            } else {
                nge[i] = s.top();
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

            while (!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
            }

            if (s.empty()) {
                s.push(i);
            } else {
                pge[i] = s.top();
                s.push(i);
            }
        }

        long long minSum = 0;
        long long maxSum=0;

        for (int i = 0; i < n; i++) {
            long long a = 1LL*(i - pse[i]) * nums[i];
            long long b = 1LL*(i - pge[i]) *nums[i];
            minSum +=  1LL*(nse[i] - i) * a;
            maxSum +=1LL*(nge[i]-i)*b;
        }

        return maxSum-minSum;

    
    }
};