class Solution {
public:
    vector<int> memo; 
    // This helper function will contain the original recursive logic.
    int fib_helper(int n) {
        if (n <= 1) {
            return n;
        }
        // CHANGED: We check against our sentinel value (-1) now.
        // This is robust and correctly handles cases where the result is 0.
        if (memo[n] != -1) {
            return memo[n];
        }
        return memo[n] = fib_helper(n - 1) + fib_helper(n - 2);
    }

    int fib(int n) {
        // CHANGED: The memo table is now sized and initialized here, since 'n' is known.
        // We fill it with -1, which acts as a sentinel to mean "not yet computed".
        memo.assign(n + 1, -1);
        return fib_helper(n);
    }
};