// Your original code with minimal changes
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // --- START OF CHANGES ---

        // Use a min-heap to find the k largest elements in O(N log k) time and O(k) space.
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop(); // CHANGED: Instead of building a full max-heap, we maintain a min-heap of size k.
            }
        }

        vector<int> ans;
        unordered_map<int, int> kLargest;
        while(!minHeap.empty()) {
            kLargest[minHeap.top()]++; // CHANGED: Populate the map from the final min-heap.
            minHeap.pop();
        }
        
        // --- END OF CHANGES ---


        // This part of your logic is already optimal and requires no changes.
        // now iterate on the array
        for (int i = 0; i < nums.size(); i++) {
            if (kLargest.find(nums[i]) != kLargest.end()) {
                // means it exist so add it into ans array delete the freq also
                if (kLargest[nums[i]] > 0) { // CHANGED: Check for > 0 to be more explicit.
                    ans.push_back(nums[i]);
                    kLargest[nums[i]]--;
                }
            }
        }
        return ans;
    }
};