class Solution
{
    public:
        int minElement(vector<int> &nums)
        {
            int ans=INT_MAX;
            int n=nums.size();
            for(int i=0;i<n;i++){
                int temp=0;
                while(nums[i]>0){
                    temp+=nums[i]%10;
                    nums[i]/=10;
                }
                ans=min(temp,ans);
            }
            return ans;
        }
};