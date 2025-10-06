class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //sliding window approach once again

        //KADANE ALGORITHM
        int n=nums.size(); int i=0; int j=1; int sum=nums[0]; int tempSum=nums[0];

        //yaad aagya ham zero and negative dekhte the if prefix sum is zero or negative then neglect it in the window collapse the window otherwise keep expanding and updating sum=max(sum, currentSum);
        while(j<n){
            
            if(tempSum<0){
                //no sense to update here
                //reset the sum and make the i close to j
                tempSum=0;
            }
            tempSum+=nums[j];
            sum=max(sum,tempSum);
            j++;
        }
        return sum;
    }
};