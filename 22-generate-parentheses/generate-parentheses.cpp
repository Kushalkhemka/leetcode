class Solution {
public:
    vector<string> ans;
    void fn(string s, int n, int bc,
            int bo) // bracket opening and brack closing (bo & bc)
    {
        if (bc == n && bo == n) {
            ans.push_back(s);
        }

        // add bo
        if (bo < n) {
            fn(s + "(", n, bc, bo+1);
        }

        if(bc < bo && bc < n){
            fn(s + ")", n, bc+1, bo);
        }
    }
    vector<string> generateParenthesis(int n) {
        fn("",n,0,0);
        return ans;
    }
};