/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */

 //less space complexity

var rotate = function(nums, k) {
    k = k % nums.length;  // To handle cases where k > nums.length
    const temp=[];
    for(let i=nums.length-1;i>=nums.length-k;i--){
        temp.push(nums[i]);
    }

    for(let j=nums.length-1;j>=k;j--){
        nums[j]=nums[j-k];
    }
    temp.reverse()
    for(let z=0;z<k;z++){
        nums[z]=temp[z]
    }

};

//more readable, more space complexity

var rotate = function(nums, k) {
    k=k% nums.length
    nums.unshift(...   nums.splice(nums.length-k))

};