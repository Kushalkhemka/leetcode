class Solution {
public:
    int mySqrt(int x) {
        int lo=0; int hi=x;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            long long sq=(long long)mid*mid;
            if(sq==x){
                return mid; //perfect square;
            }
            else if(sq>x){
                hi=mid-1; //go left
            }
            else{
                lo=mid+1; //go right
            }
        }
        return hi;
    }
    
};