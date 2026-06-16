class Solution {
public:
    string processStr(string s) {
        // le bete tu to aate hi pil gya
        string result = "";
        for (auto& c : s) {
            if (c >= 'a' && c <= 'z') {
                result += c;
            } else if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else if (c == '#') {
                result += result;
            } else {
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};