/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

 //naive solutions O(n^2)
// var twoSum = (nums, target) => {
//     for(let i=0;i<nums.length;i++){
//         for(let j=1;j<nums.length;j++){
//             if(nums[i]+nums[j]===target){
//                 return [i,j]
//             }
//         }
//     }
// };


//optimised solution linear time O(n)
var twoSum = (nums, target) =>{
    const myObj ={};
    for(let i=0;i<nums.length;i++) {
        if(myObj.hasOwnProperty(nums[i])) {
            return [myObj[nums[i]],i];
        }
        myObj[target-nums[i]]=i;
    }

    return false;
}
