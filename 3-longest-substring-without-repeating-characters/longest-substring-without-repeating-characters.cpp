class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window go brrr
        int i = 0; // left pointer
  

        unordered_map<char,int> window; //to check if I have seen this previous in the sliding window or not in o(1). LOOKUP is o(1)
        int l=0;
        for (int k = 0; k < s.length(); k++) {
            char currentChar=s[k];
            if(window.find(currentChar)!=window.end()){
               i = max(i, window[currentChar] + 1);
            }

            window[currentChar]=k; //update new iNDDEX

            l=max(l,k-i+1);
                //doing mistake making the window not overlapping //rethink
        }
        return l;
    }
};