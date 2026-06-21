class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        //simple next greater element store the indices to get the distance
        int n=temp.size();
        vector<int> ans(n,0);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && temp[s.top()]<=temp[i]){
                s.pop();
            }
            if(s.empty()){
                s.push(i);
            }
            else{
                //s is not empty
                ans[i]=s.top()-i; 
                s.push(i);
            }
        }
        return ans;
    }
};