class Solution {
   public:
    vector<string> ans;
    void fn(const string &digits, string &curr, int idx,vector<string> &s) {
        if (idx == digits.length() && curr.length() == digits.length()) {
            ans.push_back(curr);
            return;
        }

        string letters = s[digits[idx] - '0'];

        for (int j = 0; j < letters.size(); j++) {
            curr.push_back(letters[j]);
            fn(digits, curr, idx + 1, s);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> s = {"",   "",   "abc",  "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};
        // s[3] = def , s[3][0]=d like this=
        string curr = "";
        fn(digits, curr, 0, s);
        return ans;
    }
};