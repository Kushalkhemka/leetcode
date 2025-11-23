class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int r11 = 10001, r12 = 10001, r21 = 10001, r22 = 10001, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (nums[i] % 3 == 1) {
                if (nums[i] < r11) {
                    r12 = r11;
                    r11 = nums[i];
                } else if (nums[i] < r12) {
                    r12 = nums[i];
                }
            } else if (nums[i] % 3 == 2) {
                if (nums[i] < r21) {
                    r22 = r21;
                    r21 = nums[i];
                } else if (nums[i] < r22) {
                    r22 = nums[i];
                }
            }
        }
        if (sum % 3 == 1) {
            sum -= min(r11, r21 + r22);
        } else if (sum % 3 == 2) {
            sum -= min(r21, r11 + r12);
        }
        return sum;
    }
};
