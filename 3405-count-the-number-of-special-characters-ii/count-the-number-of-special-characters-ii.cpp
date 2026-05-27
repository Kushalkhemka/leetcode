class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;

        for (char x : word) {
            char c;

            if (x >= 'a' && x <= 'z') {
                c = x;

                if (mp[c] == 0) {
                    mp[c] = 1;
                }
                else if (mp[c] == 2) {
                    mp[c] = 3;  
                }
            }
            else {
                c = x + 32; 

                if (mp[c] == 0) {
                    mp[c] = 3; 
                }
                else if (mp[c] == 1) {
                    mp[c] = 2; 
                }
            }
        }

        int cnt = 0;

        for (auto x : mp) {
            if (x.second == 2) {
                cnt++;
            }
        }

        return cnt;
    }
};