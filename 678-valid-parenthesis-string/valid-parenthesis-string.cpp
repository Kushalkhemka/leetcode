class Solution {
public:
    bool checkValidString(const string &st) {
        stack<int> s1;
        stack<int> s2;
        for (int i = 0; i < st.size(); i++) {
            if (st[i] == '(') {
                s1.push(i);
            } else if (st[i] == '*') {
                s2.push(i);
            } else {
                // c is )
                if (s1.empty() && s2.empty())
                    return false;
                else if (!s1.empty())
                    s1.pop();
                else {
                    // treated as opening bracket
                    if (s2.top() < i)
                        s2.pop();
                    else
                        return false;
                }
            }
        }

        while (!s2.empty() && !s1.empty() && s2.top() > s1.top()) {
            s1.pop();
            s2.pop();
        }

        if (s1.empty())
            return true;
        return false;
    }
};