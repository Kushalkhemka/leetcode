class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st;

        for (char ch : word) {
            st.insert(ch);
        }

        int cnt = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (st.count(ch) && st.count(ch - 32)) {
                cnt++;
            }
        }

        return cnt;
    }
};