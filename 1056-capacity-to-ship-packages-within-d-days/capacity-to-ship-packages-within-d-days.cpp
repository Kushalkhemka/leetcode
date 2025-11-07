class Solution {
public:
    bool can_Ship(vector<int>& weights,int days,int leastW){
        int daysNeeded = 1;
        int i=0; int weightSoFar=0;
        while(i<weights.size()){
            if(weights[i]>leastW) return false;
            if(weightSoFar+weights[i]<=leastW){
                weightSoFar+=weights[i];
                i++;
            }
            else{
                weightSoFar=weights[i];
                daysNeeded++;
                i++;
            }
            
        }
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