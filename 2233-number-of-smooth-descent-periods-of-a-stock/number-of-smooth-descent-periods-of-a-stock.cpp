class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = (int)prices.size();                
        long long count = 0;                      
        int i = 0;
        int j = 1;

        while (i < n) {                           
            while (j < n && prices[j - 1] - prices[j] == 1) { 
                j++;
            }
            long long len = j - i;                  
            count += len * (len + 1) / 2;         

            i = j;                                  // move to next segment
            j = i + 1;                              //restart j safely
        }
        return count;
    }
};
