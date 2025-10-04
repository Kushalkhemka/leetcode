class Solution {
public:
    bool checkString(string s) {
        int l = 0;
        int n = s.length(); // Get length of the string

        // Move 'l' past all leading 'a's
        // 'l' will stop at the first 'b' or at the end of the string if only 'a's are present
        while (l < n && s[l] == 'a') {
            l++;
        }

        // Now, starting from where 'l' stopped, all remaining characters must be 'b's
        // We can use 'l' again to check this.
        while (l < n && s[l] == 'b') {
            l++;
        }

        // If 'l' reaches the end of the string (n), it means we successfully traversed
        // all 'a's followed by all 'b's (or only 'a's, or only 'b's).
        // If 'l' did not reach 'n', it means an 'a' was found after a 'b'.
        return l == n;
    }
};