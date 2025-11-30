class Solution {
public:
    void fn(int idx, int target, vector<int>& candidates,
            vector<int>& ds, vector<vector<int>>& result) {

        // base case
        if (idx == candidates.size()) {
            if (target == 0) {
                result.push_back(ds);
            }
            return; 
        }

        // NOT TAKE
        fn(idx + 1, target, candidates, ds, result);  
                // TAKE (only if possible)
        if (candidates[idx] <= target) {              
            ds.push_back(candidates[idx]);            // pick
            fn(idx, target - candidates[idx], candidates, ds, result);
            ds.pop_back();                            // FIX: backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;

        fn(0, target, candidates, ds, result);       

        return result;
    }
};
