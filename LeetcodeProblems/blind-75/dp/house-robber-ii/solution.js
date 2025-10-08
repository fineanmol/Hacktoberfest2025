// House Robber II - LeetCode #213

/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if (nums.length === 0) return 0;
    if (nums.length === 1) return nums[0];
    
    // Rob without first
    const max1 = robLinear(nums, 1, nums.length - 1);
    // Rob without last
    const max2 = robLinear(nums, 0, nums.length - 2);
    
    return Math.max(max1, max2);
};

function robLinear(nums, start, end) {
    if (start > end) return 0;
    
    let prev = 0;
    let curr = 0;
    
    for (let i = start; i <= end; i++) {
        const temp = Math.max(prev + nums[i], curr);
        prev = curr;
        curr = temp;
    }
    
    return curr;
}
