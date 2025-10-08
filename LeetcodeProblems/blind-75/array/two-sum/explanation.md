# Two Sum - Problem #1

## Problem Statement
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

## Examples
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Input: nums = [3,2,4], target = 6
Output: [1,2]

Input: nums = [3,3], target = 6
Output: [0,1]
```

## Approach
**Key Insight**: Use a hash map to store numbers and their indices for O(1) lookups.

**Algorithm**:
1. Create a hash map to store each number and its index.
2. Iterate through the array.
3. For each number, calculate the complement (target - current number).
4. If the complement is in the map, return the indices.
5. Otherwise, add the current number and index to the map.

**Why this works**:
- One pass through the array (O(n) time)
- Constant time lookups with hash map
- Handles duplicates properly by storing indices

## Complexity Analysis
- **Time Complexity**: O(n) - Single pass through the array
- **Space Complexity**: O(n) - Hash map storage

## Key Insights
- Hash maps are ideal for "find pair that sums to target" problems
- Check for complement before adding current element to avoid using same element twice
- Returns as soon as pair is found for efficiency

## Alternative Approaches
1. **Brute Force**: Nested loops (O(n²) time)
2. **Sorting**: Sort array and use two pointers (O(n log n) time, modifies indices)

## Solutions in Different Languages

### Java
```java
import java.util.HashMap;
import java.util.Map;

// ... existing code ...
```

### JavaScript
```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const map = new Map();
    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        if (map.has(complement)) {
            return [map.get(complement), i];
        }
        map.set(nums[i], i);
    }
    return [];
};
```

### Python
```python
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_map:
                return [num_map[complement], i]
            num_map[num] = i
        return []
```

## Test Cases
```
Test Case 1:
Input: nums = [2,7,11,15], target = 9
Expected Output: [0,1]

Test Case 2:
Input: nums = [3,2,4], target = 6
Expected Output: [1,2]

Test Case 3:
Input: nums = [3,3], target = 6
Expected Output: [0,1]

Test Case 4:
Input: nums = [1,2,3,4,5], target = 10
Expected Output: [] (no solution, but problem assumes one exists)
```

## Edge Cases
1. Minimum array length (2 elements)
2. Duplicate numbers
3. Negative numbers
4. Zero as target
5. Large numbers (close to INT_MAX)

## Follow-up Questions
1. What if there are multiple pairs?
2. What if we need all pairs that sum to target?
3. What if we can't use extra space?
4. What if the array is sorted?
