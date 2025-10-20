class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
          int n=nums.size();
          int mod = 1e9 + 7; // CHANGED: Define the modulus for repeated use.
          
          vector<int> powers(n, 1); // CHANGED: Added a vector to pre-compute powers of 2.
          for (int i = 1; i < n; ++i) {
              powers[i] = (powers[i - 1] * 2) % mod; // CHANGED: Compute powers with modulo to prevent overflow.
          }

          int l=0; 
          int r=n-1;
          int result=0;
          sort(nums.begin(),nums.end()); //O(nlogn)
          while(l<=r){
            if(nums[l]+nums[r]<=target){
                //satisfies the given condition
                result = (result + powers[r-l]) % mod; // CHANGED: Use the precomputed power and apply modulo to the sum.
                l++;
            }
            else{
                r--;
            }
          }
          return result;
    }
};