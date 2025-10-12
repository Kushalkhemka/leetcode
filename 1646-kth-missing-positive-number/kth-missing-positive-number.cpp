class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // Calculate the number of missing integers on the fly
            int missingCount = arr[mid] - (mid + 1);

            if (missingCount < k) {
                // We need to find a number further to the right
                lo = mid + 1;
            } else {
                // The k-th missing number is at or before mid
                hi = mid - 1;
            }
        }

        // The loop ends when lo = hi + 1.
        // 'lo' is the index of the first element where the number of missing
        // integers is >= k.
        // This means the k-th missing number is among the numbers before arr[lo].
        // The number of elements from arr before our answer is 'lo'.
        // So, the answer is k (for the missing slots) + lo (for the present numbers).
        return lo + k;
    }
};