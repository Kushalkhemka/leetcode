class Solution {
public:

    bool isSubsequence(string s, string t) {
        //guys use the two pointer approach
        int i=0; //for s 
        int j=0; //for t
        while(i<s.length()){
            char c=s[i];//look for this c in the t
            while(t[j]!=c){
                //move the j pointer
                if(j>=t.length()) return false; //if char is not found in whole t string
                j++;
            }
            j++;
            i++;
        }
        return true; 
    }
};