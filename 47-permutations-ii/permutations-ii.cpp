class Solution {
public:
    set<vector<int>> ans;
    void fn(vector<int>& nums, int n, vector<int>& visited, vector<int>& curr) {
        if (curr.size() == n) {
            ans.insert(curr);
            return; // base case
        }
        // mark one as visited
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                curr.push_back(nums[i]);
                visited[i]=1;
                fn(nums, n,visited,curr);
                visited[i]=0;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<int> visited(n,0);
        vector<vector<int>> ansArr;
        vector<int>curr;
        fn(nums,n,visited,curr);

        for(auto x:ans){
            ansArr.push_back(x);
        }
        return ansArr;
    }

};