class Solution {
public:
    bool isPerfectSquare(int num) {
        int lo=0; int hi=num;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            long long sq=(long long)mid*mid; 
            if(sq==num) return true;
            else if(sq>num){
                hi=mid-1;//go left
            }
            else {
                lo=mid+1; //go right
            }
        }
        return false;
    }
};