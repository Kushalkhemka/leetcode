class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> missingNumbers(n);
        //linearly make the array of the missing numbers
        for(int i=0; i<n;i++){
            //misssing numbeer at ith positon is
            missingNumbers[i]=arr[i]-(i+1);
        } 
        //we have the array of the missing number apply the binary search
        int lo=0; int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(missingNumbers[mid]<k){
                //go right
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }

        // after the loop, hi is the largest index with missingNumbers[hi] < k.
        // If hi is -1, it means k is smaller than any missing count,
        // so the k-th missing number is just k.
        if (hi < 0) { // CHANGED: Added a check for the edge case.
            return k;
        }

        //after this range is [high, lo]
        return arr[hi]+(k-missingNumbers[hi]);
    }
};