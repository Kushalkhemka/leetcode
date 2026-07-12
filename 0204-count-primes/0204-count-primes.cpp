

class Solution {
public:
    int countPrimes(int n) {
        //---PRECOMPUTATION--- START
        vector<int> primes(n + 1, 1);
        if (primes.size() >= 2)
            primes[1] = 0;
        if (primes.size() >= 1)
            primes[0] = 0;
        for (long long i = 2; i * i <= n; i++) {
            for (long long j = i * i; j <= n; j += i) {
                primes[j] = 0;
            }
        }
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            cnt += primes[i];
            primes[i] = cnt;
        }

        return (n - 1 >= 0) ? primes[n - 1] : 0;
    }
};