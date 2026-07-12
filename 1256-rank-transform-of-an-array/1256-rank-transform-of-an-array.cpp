class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        vector<int> ans(n);
        int i = 1;
        for (auto& [val, indices] : mp) {
            for (auto& idx : indices) {
                ans[idx] = i;
            }
            i++;
        }
        return ans;
    }
};