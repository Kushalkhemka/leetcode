class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(); // no of rows
        vector<int> trailingZeroes(n);
        for (int i = 0; i < n; i++) {
            for (int j = grid[0].size()- 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    trailingZeroes[i]++;
                } else
                    break;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            int need=n-i-1;
            int j=i;
            while(j<n && trailingZeroes[j]<need) j++;
            if(j==n) return -1; //no candidate row found for swapping
            
            //candidate row found now bubble it up to ith pos
            while(j>i){
                swap(trailingZeroes[j],trailingZeroes[j-1]);
                cnt++;
                j--;
            }
        }
        return cnt;
    }
};