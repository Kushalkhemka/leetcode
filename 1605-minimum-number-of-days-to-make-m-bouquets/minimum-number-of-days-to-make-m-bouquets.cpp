class Solution {
public:
    bool can_make(vector<int> &bloomDay,int d,int m,int k){
        int cons_so_far=0;int nb=0; //number of boquote
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=d){
                cons_so_far++;
                if(cons_so_far==k){
                    nb++;
                    cons_so_far=0;
                }
            }
            else{
                cons_so_far=0;
            }
        }
        return nb>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()) return -1; 
        long long ans=0;
        long long lo=*std::min_element(bloomDay.begin(), bloomDay.end());
        long long hi=*std::max_element(bloomDay.begin(), bloomDay.end());
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if(can_make(bloomDay,mid,m,k)){
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