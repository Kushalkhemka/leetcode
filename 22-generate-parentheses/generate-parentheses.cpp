class Solution {
public:
    vector<string> ans;

    void fn(string& s, int n, int bc, int bo) {
        if (bc == n && bo == n) {
            ans.push_back(s);
            return;
        }

        if (bo < n) {
            s.push_back('(');
            fn(s, n, bc, bo + 1);
            s.pop_back();
        }

        if (bc < bo) {
            s.push_back(')');
            fn(s, n, bc + 1, bo);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        fn(s, n, 0, 0);
        return ans;
    }
};