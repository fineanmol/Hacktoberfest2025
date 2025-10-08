// Missing Number - LeetCode #268

/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let xor = 0;
    for (let i = 0; i <= nums.length; i++) {
        xor ^= i;
    }
    for (let num of nums) {
        xor ^= num;
    }
    return xor;
};
