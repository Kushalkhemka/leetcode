class Solution {
public:
    int maxOperations(string s) {
        int noOf1=0; int op=0; int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='1') noOf1++;
            if(s[i]=='0' && s[i+1]=='1'){
                op+=noOf1; 
            }
            else if(i==n-1 && s[i]=='0') op+=noOf1; 
        }
        return op;
    }
};