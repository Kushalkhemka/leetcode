class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        //solution with the Dynamic Programming
        int n=energy.size();
       
        for(int i=n-1;i>=0;i--){
            if(i+k<n) energy[i]=energy[i]+energy[i+k]; //overwriting with the prefix sum since we already have the sum ahead of of the term i+2k i+3k at the positon of i+k itself and so on since the problems are overlapping we can use dp to memoise in-place only with the suffix sum. This is the SUFFIX SUM pattern.
            else energy[i]=energy[i];
        }
    int max=INT_MIN;
    for(int i=0; i<n;i++){
        if(energy[i]>max) max=energy[i];
    }
    return max;
    }
};