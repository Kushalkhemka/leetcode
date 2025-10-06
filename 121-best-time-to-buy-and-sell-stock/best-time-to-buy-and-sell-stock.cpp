class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // two pointer approach
        int n = prices.size();
        int i = 0;
        int j = n - 1;
        int maxProfit = 0; //sell price
        int minPrice = INT_MAX; //buy price
        // while (i <= j) {
           
        //         //if price kam h toh bhai dekho ki baad me kam hone ke chance hai kya and check kro ki jldi bechna pdegha aese to fir 
        //         minPrice=min(minPrice,prices[i]);
        //         maxPrice=max(maxPrice,prices[j]);
        //         i++; j--;
        
        // }
        // return (maxPrice-minPrice)>0?maxPrice-minPrice:0;

        for(int i=0;i<n;i++){
            maxProfit=max(maxProfit,prices[i]-minPrice);
            minPrice=min(minPrice,prices[i]);
        }
        return maxProfit;
    }
};