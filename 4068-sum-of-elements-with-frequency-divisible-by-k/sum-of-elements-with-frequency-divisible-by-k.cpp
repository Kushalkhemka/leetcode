class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        //     unordered_map<int,int> freqmap;
        //     for(int i:nums){
        //         freqmap[i]++; //increasing the freq
        //     }
        //     int sum=0;
        //     for(auto &[val,freq]:freqmap){
        //         if(freq%k==0){
        //             sum+=val*freq;
        //         }
        //     }
        //     return sum;
        // }

        // MORE OPTIMISED
        //  Alternative single-pass loop structure
        unordered_map<int, int> freqmap;
        long long current_sum = 0; // Using long long for safety

        for (int val : nums) {
            int old_freq = freqmap[val];

            // If val's old count was a multiple of k, its contribution was in
            // the sum. Since the count is changing, we must remove the old
            // contribution.
            if (old_freq > 0 && old_freq % k == 0) {
                current_sum -= (long long)val * old_freq;
            }

            int new_freq = ++freqmap[val];

            // If val's new count is a multiple of k, add its new contribution.
            if (new_freq % k == 0) {
                current_sum += (long long)val * new_freq;
            }
        }
        // The function would then return current_sum
        return current_sum;
    }
    
};