class Solution {
public:
    int reverse(int x) {
        long long res=0;
        while(x){
            int digit=x%10;
            res=(res*10)+digit;
            x/=10;
        }   
        
        if(res>INT_MAX||res<INT_MIN){
            return 0;
        }

        return (int)res;
    }
};