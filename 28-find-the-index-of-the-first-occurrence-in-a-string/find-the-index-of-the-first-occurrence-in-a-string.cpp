class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // ADDED: Handle the edge case of an empty needle.

        int j=0;
        int startIdx=-1;
        for(int i=0; i<haystack.length(); i++){   
            if(haystack[i] == needle[j]){
                if(j==0) startIdx=i; // Record the start of a potential match.
                j++;
            }
            else{
                if (startIdx != -1) { // If we were in the middle of a partial match...
                    i = startIdx;     // CHANGED: ...rewind 'i'. The loop's i++ will then correctly advance to the next character.
                }
                j=0;              // Reset needle pointer.
                startIdx = -1;    // Reset the potential start index.
            }

            if (j == needle.length()) { // CHANGED: Check for a full match immediately after a character match.
               return startIdx; // If found, we can return the starting index right away.
            }
        }
        return -1; // CHANGED: If the loop finishes without a return, no match was found.
    }
};