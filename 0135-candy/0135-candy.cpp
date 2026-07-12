class Solution {
public:
    int candy(vector<int>& rating) {
        int sum = 1;
        int n = rating.size();
        int i = 1;

        while (i < n) {

            while (i < n && rating[i - 1] == rating[i]) {
                sum += 1;
                i++;
            }
            int peak = 1;
            while (i < n && rating[i - 1] < rating[i]) {
                peak++;
                sum += peak;
                i++;
            }

            int dcandy = 1;

            while (i < n && rating[i - 1] > rating[i]) {
                // rating[i-1]>[i] downhill
                sum += dcandy;
                i++;
                dcandy++;
            }

            // peak
            if (dcandy > peak) {
                // to modify kreghe otherwise
                sum += dcandy - peak;
            }
        }

        return sum;
    }
};