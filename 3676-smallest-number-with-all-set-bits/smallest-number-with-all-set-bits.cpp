class Solution {
public:
    int smallestNumber(int n) {
        //left shift operator 2^n se dekh lungha
        int i=0; int greaterOne=0;
        if(n==1 || n==0) return 1;
        while(greaterOne<=n){
            greaterOne=1<<i;
            i++;
        }
        return greaterOne-1;
    }
};