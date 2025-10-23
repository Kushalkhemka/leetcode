class Solution {
public:
    bool hasSameDigits(string s) {
        //easy shit //convert char to int
       
        while(s.length()!=2){
            int i=0;
            //new stirng 
            string ans;
            while(i<s.length()-1){
                int n=((s[i]-'0')+(s[i+1]-'0'))%10;
                ans.push_back(char(n));
                i++;
            }
            s=ans;

        }
        if(s.length()==2){
            return s[0]==s[1]; //this would work without c-'0'
        }
        return false;  //unreachable code 
    }
};