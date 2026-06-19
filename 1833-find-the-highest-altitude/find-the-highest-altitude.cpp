class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0; int prev=0;
        for(int i=0;i<gain.size();i++){
            int diff= gain[i]+prev;
            prev=diff;
            maxi=max(diff,maxi);
        }
        return maxi;
    }
};