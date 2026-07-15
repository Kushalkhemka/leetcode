class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = pow(n, 2);
        int sumEven = n * (n + 1);

        return gcd(sumOdd, sumEven);
    }
};