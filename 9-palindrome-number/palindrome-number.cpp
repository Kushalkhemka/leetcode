class Solution {
public:
    bool isPalindrome(int x) {
        //reverse the number and check 
        long long res=0;
        int original=x;
        if(x<0) return false;
        while(x){
            int digit=x%10;
            res=(res*10)+digit;
            x/=10;
        }

        return res==original;
    }
};