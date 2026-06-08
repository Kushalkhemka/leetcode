class Solution {
public:
     long long MOD = 1000000007;
     long long power(long long x, long long n) {
        if (n == 0)
            return 1;
        long long half = power(x, n / 2);
        if (n % 2 == 0)
            return half * half % MOD;
        else
            return x * half * half % MOD;
    }
   
    int countGoodNumbers(long long n) {

        long long fiveCount = 0;
        long long fourCount = 0;
        if (n % 2 == 0)
            fiveCount = fourCount = n / 2;
        else {
            fourCount = n / 2;
            fiveCount = fourCount + 1;
        }
        long long ans = (power(4, fourCount)% MOD * power(5, fiveCount)% MOD);
        return ans%MOD;
    }
};