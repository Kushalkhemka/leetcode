class Solution {
public:
    int romanCharToVal(char c) {
        // ... (your helper function is perfect, no changes needed)
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    
    int romanToInt(string s) {
        int l = s.length();
        int ans = 0; // CHANGED: Always initialize your result variable to 0.

        // Loop until i is past the end of the string.
        // The increment (i++ or i+=2) is handled inside the loop body.
        for (int i = 0; i < l; ) {
            // First, check for two-character subtraction cases.
            // We must also check that i+1 is a valid index to avoid errors.
            if (i + 1 < l && s[i] == 'I' && s[i+1] == 'V') { // CHANGED: Use '==' for comparison.
                ans += 4;
                i += 2; // CHANGED: Skip over both 'I' and 'V'.
            } else if (i + 1 < l && s[i] == 'I' && s[i+1] == 'X') {
                ans += 9;
                i += 2;
            } else if (i + 1 < l && s[i] == 'X' && s[i+1] == 'L') {
                ans += 40;
                i += 2;
            } else if (i + 1 < l && s[i] == 'X' && s[i+1] == 'C') {
                ans += 90;
                i += 2;
            } else if (i + 1 < l && s[i] == 'C' && s[i+1] == 'D') {
                ans += 400;
                i += 2;
            } else if (i + 1 < l && s[i] == 'C' && s[i+1] == 'M') {
                ans += 900;
                i += 2;
            } else {
                // If no subtraction case matches, it's a single character.
                // This is the "else" part you requested.
                ans += romanCharToVal(s[i]);
                i += 1; // CHANGED: Move forward by one character.
            }
        }
        return ans; // CHANGED: A function that returns int must have a return statement.
    }
};