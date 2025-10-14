class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // make a min heap and extract
        std::priority_queue<int> maxHeap(nums.begin(), nums.end());
        vector<int> ans;
        unordered_map<int, int> kLargest;
        for (int i = 0; i < k; i++) {
            kLargest[maxHeap.top()]++;
            maxHeap.pop(); // extract top k max
        }

        // now iterate on the array
        for (int i = 0; i < nums.size(); i++) {
            if (kLargest.find(nums[i]) != kLargest.end()) {
                // means it exist so add it into ans array delete the freq also
                if (kLargest[nums[i]]) {
                    ans.push_back(nums[i]);
                    kLargest[nums[i]]--;
                }
                else{
                    continue;
                }
            }
        }
        return ans;
    }
};