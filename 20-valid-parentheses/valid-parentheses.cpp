class Solution {
public:
    bool checkOpp(char c1, char c2) {
        return (c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') ||
               (c1 == '[' && c2 == ']');
    }
    bool isValid(string s) {
        stack<int> stk;
        int i = 0;
        // push initial element
        
        while (i<s.length()){
                if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                    // let opening brack go into stack and pop out the closing
                    // brack while matching at each step
                    stk.push(s[i]);
                    i++;
                } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                    if (!stk.empty() && checkOpp(stk.top(), s[i])) {
                        stk.pop();
                        i++;
                    } else
                        return false;
                } else {
                    return false;
                }
            }
        if(!stk.empty()) return false;
        return true;
    }
};