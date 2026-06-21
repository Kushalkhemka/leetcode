class Solution {
public:
    int minAddToMakeValid(const string &st) {
        int open=0;
        int cnt=0;
        for(auto &c:st){
            if(c=='(') open++;
            else{
                if(open==0) cnt++;
                else open--;
            }
        }

        cnt+=open;
        return cnt;
    }
};