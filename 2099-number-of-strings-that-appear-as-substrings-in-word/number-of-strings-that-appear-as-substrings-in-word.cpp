class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        //generate all the substrings
        unordered_set<string> st;
        int l=word.length();
        for(int i=0;i<l;i++){
            for(int j=i;j<l;j++){
                st.insert(word.substr(i,j-i+1));
            }
        }

        int cnt=0;
        for(auto &s:patterns){
            if(st.find(s)!=st.end())cnt++;
        }
        return cnt;
    }
};