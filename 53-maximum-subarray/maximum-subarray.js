/**
 * @param {number[]} nums
 * @return {number}
 */
const maxSubArray = (nums) => {

    let current_sum = nums[0];
    let max_sum = nums[0];

    for (let i = 1; i < nums.length; i++) {
        current_sum = Math.max(nums[i], current_sum + nums[i]);
        max_sum = Math.max(current_sum, max_sum);
    }

    return max_sum;

};