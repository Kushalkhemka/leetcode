class Solution {
public:
    bool isFeasible(vector<int>&piles, int k, int h){
    long long sumHour = 0; // CHANGED: Use long long to prevent overflow
    for(int i : piles){
        sumHour += (long long)(i + k - 1) / k; // Also good practice to cast here
    }
    if(sumHour <= h){
        return true;
    }
    else return false;
}
    
    int minEatingSpeed(vector<int>& piles, int h) {
        //apply binary search on min(piles)....max(piles)
        int minK=INT_MAX; int maxK=INT_MIN;
        for(int i:piles){
            if(i>maxK) maxK=i;
            if (i<minK) minK=i;
        }
        

        //b.s on answers
        int n=piles.size(); int lo=1;
        int hi=maxK; int potentionalAns=hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            //check the feasibility
            if(isFeasible(piles, mid,h)){
                //potentional answer and go on left side
                potentionalAns=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return potentionalAns;
    }
};