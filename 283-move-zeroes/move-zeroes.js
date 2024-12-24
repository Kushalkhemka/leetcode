/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let idx=0; //idx=0
    for(let i=0;i<nums.length;i++){
        if(nums[i]!=0){
            [nums[idx], nums[i]] = [nums[i], nums[idx]];idx++;
        }
    }
};