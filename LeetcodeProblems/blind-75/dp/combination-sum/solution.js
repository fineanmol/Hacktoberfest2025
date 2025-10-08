// Combination Sum - LeetCode #39

/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    const result = [];
    
    function backtrack(temp, remain, start) {
        if (remain < 0) return;
        if (remain === 0) {
            result.push([...temp]);
            return;
        }
        
        for (let i = start; i < candidates.length; i++) {
            temp.push(candidates[i]);
            backtrack(temp, remain - candidates[i], i);
            temp.pop();
        }
    }
    
    backtrack([], target, 0);
    return result;
};
