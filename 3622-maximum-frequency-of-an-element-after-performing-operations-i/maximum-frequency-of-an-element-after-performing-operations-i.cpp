class Solution {
public:
    int lowerBound(vector<int>&nums, int target){ //greater than just greater than target only in this case
        int lo=0; int hi=nums.size()-1;
        int ans=nums.size();
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>=target){
                ans=mid;
                //go left
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }



     int upperBound(vector<int> &nums, int target){
        int ans=nums.size();
        int lo=0; int hi=nums.size()-1; 
        while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            if(nums[mid]<=target){
                //store the current as the potentional ans
                //search right half for possibilities of greater number which is less than or equal to x
                lo=mid+1;
            }
            else{
                //if mid is less than the ex and then search on the right half
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;
    }

    
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end());

    // Step 1: Create a list of all important candidate targets.
    // Using a set to handle duplicates automatically.
    set<long long> candidates;
    for (int num : nums) {
        candidates.insert(num);
        candidates.insert((long long)num - k);
        candidates.insert((long long)num + k);
    }

    int maxFinalFreq = 1;

    // Step 2: Loop through each candidate target.
    for (long long target : candidates) {
        
        // Step 3: Use your helper functions (which are correct!) to find the answer for this target.
        
        // Count elements already equal to target (important if target is in nums)
        int initialFreq = upperBound(nums, target) - lowerBound(nums, target);

        // Count all elements that could possibly become the target
        // Note: The range must be cast to int for your helpers, or helpers must accept long long
        int totalConvertible = upperBound(nums, target + k) - lowerBound(nums, target - k);
        
        int opsNeeded = totalConvertible - initialFreq;
        
        int successfulConversions = min(opsNeeded, numOperations);
        
        maxFinalFreq = max(maxFinalFreq, initialFreq + successfulConversions); 
    }
    return maxFinalFreq;
}
};