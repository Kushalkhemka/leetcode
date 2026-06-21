class Solution {
public:
    int minAddToMakeValid(const string &st) {
        stack<int>s;
        int cnt=0;
        for(auto &c:st){
            if(c=='(') s.push(c);
            else{
                if(s.empty()) cnt++;
                else s.pop();
            }
        }

        cnt+=s.size();
        return cnt;
    }
};