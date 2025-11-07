class Solution {
public:
    bool can_Ship(const vector<int>& weights, int days, int capacity) {
    int daysNeeded = 1;      // We always start on Day 1.
    int currentWeight = 0;   // The weight loaded on the current day.

    for (int w : weights) {
        // The check for w > capacity is implicitly handled by the binary search's
        // lower bound `lo = *max_element(...)`, but it's good practice to keep.
        if (w > capacity) return false;

        if (currentWeight + w <= capacity) {
            // The package fits on the current day.
            currentWeight += w;
        } else {
            // The package does not fit. We must start a new day.
            daysNeeded++;
            currentWeight = w; // This package is the first on the new day.
        }
    }

    // After checking all packages, see if the days we needed are within the budget.
    return daysNeeded <= days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=*std::max_element(weights.begin(),weights.end());
        int n=weights.size();int sum=0; int ans=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }
        int hi=sum; 
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(can_Ship(weights,days,mid)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};