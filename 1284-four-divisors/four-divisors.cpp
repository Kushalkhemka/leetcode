class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;

        for (int n : nums) {
            int cnt = 0;   
            int sum = 0;  

            for (int d = 1; 1LL * d * d <= n; d++) {
                if (n % d == 0) {
                    int a = d;
                    int b = n / d;

                    cnt++;
                    sum += a;

                    if (a != b) {   
                        cnt++;
                        sum += b;
                    }

                    if (cnt > 4) break; 
                }
            }

            if (cnt == 4) total += sum;
        }

        return total;
    }
};
