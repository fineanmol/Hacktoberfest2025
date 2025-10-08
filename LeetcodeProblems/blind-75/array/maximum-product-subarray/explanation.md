# Maximum Product Subarray - Problem #152

## Problem Statement
Given an integer array `nums`, find a subarray (containing at least one number) that has the largest product, and return that product.

The test cases are generated so that the answer will fit in a 32-bit integer.

## Examples
```
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

## Approach
**Key Insight**: Track both maximum and minimum products due to negative numbers.

**Algorithm**:
1. Initialize max, min, and result to first element.
2. For each subsequent element:
   - Calculate new max considering current, max*current, min*current
   - Update min similarly
   - Update result with new max
3. Return result

**Why this works**:
- Handles negative numbers flipping signs
- O(n) time
- Deals with zeros resetting products

## Complexity Analysis
- **Time Complexity**: O(n) - Single pass
- **Space Complexity**: O(1) - Constant space

## Key Insights
- Must track min product for negative flips
- Similar to Kadane but with max and min
- Zeros are handled naturally

## Alternative Approaches
1. **Brute Force**: All subarrays (O(n²))
2. **DP Table**: 2D DP (O(n²) space)

## Solutions in Different Languages

### Java
```java
// Maximum Product Subarray - LeetCode #152

class Solution {
    public int maxProduct(int[] nums) {
        if (nums.length == 0) return 0;
        
        int max = nums[0];
        int min = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            int tempMax = Math.max(nums[i], Math.max(max * nums[i], min * nums[i]));
            min = Math.min(nums[i], Math.min(max * nums[i], min * nums[i]));
            max = tempMax;
            
            result = Math.max(result, max);
        }
        
        return result;
    }
}
```

### JavaScript
```javascript
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
```

### Python
```python
# Maximum Product Subarray - LeetCode #152

from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        max_prod = nums[0]
        min_prod = nums[0]
        result = nums[0]
        
        for i in range(1, len(nums)):
            temp_max = max(nums[i], max_prod * nums[i], min_prod * nums[i])
            min_prod = min(nums[i], max_prod * nums[i], min_prod * nums[i])
            max_prod = temp_max
            
            result = max(result, max_prod)
        
        return result
```

## Test Cases
```
Test Case 1:
Input: [2,3,-2,4]
Expected: 6

Test Case 2:
Input: [-2,0,-1]
Expected: 0
```

## Edge Cases
1. Single element
2. All negatives
3. With zeros
4. Mixed signs
5. Empty array

## Follow-up Questions
1. What if we need the subarray?
2. What if floating points?
3. What if very large numbers?
