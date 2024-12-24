/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    var mySet = new Set();
    for(let i=0;i<nums.length;i++){
        if(mySet.has(nums[i])){
            return true;
        }
        mySet.add(nums[i]);
    }
    return false;
    
};