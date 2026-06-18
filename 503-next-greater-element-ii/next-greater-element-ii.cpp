class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        vector<int> arr1(n,-1); 
       

        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                s.push(nums[i]);
                continue;
            }
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            if(s.empty()){
                s.push(nums[i]);
            }
            else{
                arr1[i]=s.top();
                s.push(nums[i]);
            }
        }

        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                s.push(nums[i]);
                continue;
            }
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            if(s.empty()){
                s.push(nums[i]);
            }
            else{
                arr1[i]=s.top();
                s.push(nums[i]);
            }
        }

        return arr1;
        
    }
};