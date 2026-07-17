

class Solution {
public:
    int count = 0;
    void merge(int low, int mid, int high, vector<int>& nums) {
        int left = low;
        int right = mid + 1;
        int lastIdx = mid;
        // i have [left..mid] & [mid+1..high]
        //[6,13,21,25] .... [1,2,3,4,4,5,9,11,13]
        //
        for (int i = left; i <= mid && lastIdx <= high; i++) {
            for (int j = lastIdx + 1; j <= high; j++) {
                if ((long long)nums[i] > 2LL * nums[j]) {
                    count += (mid - i + 1);
                    lastIdx = j;
                } else
                    break;
            }
        }
        vector<int> temp;
        while (left <= mid && right <= high) {
            // now we need to merge them
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                // nums right is shorter
                temp.push_back(nums[right]);
                right++;
            }
        }
        // any of the loop will execute always
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // now copy the temp back to the nums from low to index
        int k = 0;
        for (int i = low; i <= high; i++) {
            nums[i] = temp[k];
            k++;
        }
    }
    void mergeSort(int low, int high, vector<int>& nums) {
        if (low >= high) {
            return;
        }

        int mid = low + (high - low) / 2;

        mergeSort(low, mid, nums);
        mergeSort(mid + 1, high, nums);

        merge(low, mid, high, nums);
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(0, nums.size() - 1, nums);
        return count;
    }
};