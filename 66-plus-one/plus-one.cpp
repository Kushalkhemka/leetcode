class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        if (digits[length - 1] < 9) {
            digits[length - 1] += 1;
            return digits;
        }
        int i = 1;
        while (digits[length - i] == 9) {
            digits[length - i] = 0;
            i++;
            if (length - i < 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
        digits[length-i]++;
        return digits;
    }
};