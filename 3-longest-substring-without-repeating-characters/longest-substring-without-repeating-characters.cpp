class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.length();
        int count = 0;
        int maxcount = 0;
        std::unordered_set<char> charSet;
        for (int j = 0; j < n; ++j) {

            // CHANGED: Logic to handle duplicates.
            // If the character at j is already in our set, we must shrink the
            // window from the left.
            while (charSet.count(s[j])) {
                // Remove the character at the left pointer 'i' and move 'i'
                // forward.
                charSet.erase(s[i]);
                i++;
            }

            // After the window is valid (no duplicate of s[j]), add the new
            // character.
            charSet.insert(s[j]);

            // CHANGED: Update maxcount with the correct length of the current
            // valid window.
            maxcount = std::max(maxcount, j - i + 1);
        }
        return maxcount;
    }
};