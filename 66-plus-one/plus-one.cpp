class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //lessgo beta
        int n=digits.size();
        int i=n-1;
        while(i>=0){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i]=0;
                i--;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
                       
        }
};