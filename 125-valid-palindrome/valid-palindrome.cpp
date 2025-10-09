class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0;
        string sanitised_string="";
        /// sanitise the string first every character
        // remove the white spaces and the non alphanumerical character
        // a empty string is a palindrome after sanitisation
        for (char c : s) {
            if (std::isalnum(c)){
                sanitised_string+=tolower(c);
            }
            
        }
        int j = sanitised_string.length()-1;
        while(i<j){
            if(sanitised_string[i]!=sanitised_string[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};