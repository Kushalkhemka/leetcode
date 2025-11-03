class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        //two 1pointer approach
        int i=0; int j=1; int n=neededTime.size();
        int ans=0;
        while(j<n){
            if(colors[j]==colors[i]){
                //dono same h to add one min and last idx save kr lo
                if(neededTime[j]>neededTime[i]) 
                {
                    ans+=neededTime[i];
                    i=j;

                }
                else{
                    ans+=neededTime[j];
                    //i remains on same position
                }   
                j++;
            }
            else{
                i = j;      // CHANGED: Reset 'i' to the start of the new color group.
                j++;
            }
        }
        return ans;
        
    }
};