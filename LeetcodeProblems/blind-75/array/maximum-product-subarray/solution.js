// Maximum Product Subarray - LeetCode #152

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    if (nums.length === 0) return 0;
    
    let max = nums[0];
    let min = nums[0];
    let result = nums[0];
    
    for (let i = 1; i < nums.length; i++) {
        const tempMax = Math.max(nums[i], Math.max(max * nums[i], min * nums[i]));
        min = Math.min(nums[i], Math.min(max * nums[i], min * nums[i]));
        max = tempMax;
        
        result = Math.max(result, max);
    }
    
    return result;
};
