class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //make a monotonic queue
      deque<int> mq;
        vector<int> ans;
        int n=nums.size();
        for(int i=0; i< k;i++){
            while(!mq.empty() && mq.front()<=nums[i]){
                mq.pop_front();
            }
           mq.push_back(nums[i]);
            
        }
        ans.push_back(mq.front());
        for(int i=k;i<n;i++){
            if(!mq.empty() && mq.front()==nums[i-k]) mq.pop_front(); //movve the sliding window to left
            while(!mq.empty() && mq.back()<=nums[i]){
                mq.pop_back();
            }
            mq.push_back(nums[i]);
            ans.push_back(mq.front());
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // make a monotonic queue
        deque<int> mq; 
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) { 

            if (!mq.empty() && mq.front() <= i - k) {
                mq.pop_front(); // remove index outside current window
            }

            while (!mq.empty() && nums[mq.back()] <= nums[i]) {
                mq.pop_back(); // remove smaller/equal values from back using indexes
            }

            mq.push_back(i); // push index, not nums[i]

            if (i >= k - 1) {
                ans.push_back(nums[mq.front()]); //  front index gives max value
            }
        }

        return ans;
    }
};