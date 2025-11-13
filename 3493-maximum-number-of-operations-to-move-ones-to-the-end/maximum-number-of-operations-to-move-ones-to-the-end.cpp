class Solution {
public:
    int maxOperations(string s) {
        int ones = 0;
        int ops = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones++;
            } else { // s[i] == '0'
                
                if (i > 0 && s[i - 1] == '1') {
                    ops += ones;
                }
            }
        }
         return ops;
    }
       
    };