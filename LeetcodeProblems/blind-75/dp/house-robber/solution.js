// House Robber - LeetCode #198

/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if (nums.length === 0) return 0;
    if (nums.length === 1) return nums[0];
    
    let prev = nums[0];
    let curr = Math.max(nums[0], nums[1]);
    
    for (let i = 2; i < nums.length; i++) {
        const temp = Math.max(prev + nums[i], curr);
        prev = curr;
        curr = temp;
    }
    
    return curr;
};
