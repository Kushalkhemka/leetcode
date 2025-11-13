class Solution {
public:
    int maxOperations(string s) {
        // Alternative logic: trigger on a "1" -> "0" transition.
        int ones = 0;
        int ops = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones++;
            } else { // s[i] == '0'
                // This condition is true only at the START of a block of zeros
                // that is preceded by at least one '1'.
                if (i > 0 && s[i - 1] == '1') {
                    ops += ones;
                }
            }
        }
         return ops;
    }
       
    };