class Solution {
public:
    // void eval(const string& s, stack<int>& st) {
    //     int op2 = st.top();
    //     st.pop();
    //     int op1 = st.top();
    //     st.pop();
    //     if (s == "+") {
    //         st.push(op1 + op2);
    //     } else if (s == "*") {
    //         st.push(op1 * op2);
    //     } else if (s == "-") {
    //         st.push(op1 - op2);
    //     } else if (s == "/") {
    //         st.push(op1 / op2);
    //     } else
    //         return;
    // }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const auto& s : tokens) {
            if (s == "+" || s == "-" || s == "/" || s == "*") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                if (s == "+") {
                    st.push(op1 + op2);
                } else if (s == "*") {
                    st.push(op1 * op2);
                } else if (s == "-") {
                    st.push(op1 - op2);
                } else {
                    st.push(op1 / op2);
                }
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};