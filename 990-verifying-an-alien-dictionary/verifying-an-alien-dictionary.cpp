class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> priority(26, -1);
        for (int i = 0; i < 26; i++) {
            priority[order[i] - 'a'] = i; // higher priority is higher
        }

        for (int k = 0; k < words.size() - 1; k++) {
            string a = words[k];
            string b = words[k + 1];
            int i = 0;
            int j = 0;
            while (i < a.length() && j < b.length()) {
                if (a[i] != b[j]) {
                    if (priority[a[i]-'a'] > priority[b[j]-'a'])
                        return false;
                    break;
                }
                i++;j++;
            }
            if (i < a.length() && j == b.length()) //a still has characters left & b has ended
                return false;
        }
        return true;
    }
};