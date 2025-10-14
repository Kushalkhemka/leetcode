class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        //basically array bana lu ki ending index kya hai jahatk increasing subarray h
        int l=0; int n=nums.size();
        while(l<n){
            int r=l;
            while(r+1<n && nums[r]<nums[r+1]) r++;
            int len=r-l+1;
            if(len>=2*k) return true;

            //if breaks earlier then check again for second segment
            r++;
            l=r; //moving left pointer to start of second segment
            while(r+1<n && nums[r]<nums[r+1]) r++;
            int nextlen=r-l+1;
            if(nextlen>=k && len>=k) return true;
        }
        return false;
    }
};