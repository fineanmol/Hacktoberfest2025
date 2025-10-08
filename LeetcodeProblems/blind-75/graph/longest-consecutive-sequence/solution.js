// Longest Consecutive Sequence - LeetCode #128

/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    const set = new Set(nums);
    let maxLength = 0;
    
    for (let num of set) {
        if (!set.has(num - 1)) {
            let current = num;
            let length = 1;
            
            while (set.has(current + 1)) {
                current++;
                length++;
            }
            
            maxLength = Math.max(maxLength, length);
        }
    }
    
    return maxLength;
};
