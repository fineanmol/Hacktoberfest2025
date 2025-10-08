# Product of Array Except Self - Problem #238

## Problem Statement
Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

## Examples
```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

## Approach
**Key Insight**: Use two passes to calculate left and right products without division.

**Algorithm**:
1. Initialize result array with left products (prefix products from left).
2. Traverse from right, multiplying right products (postfix products).

**Why this works**:
- O(n) time, O(1) extra space (excluding output)
- Avoids division to handle zeros properly
- Combines prefix and postfix products

## Complexity Analysis
- **Time Complexity**: O(n) - Two passes
- **Space Complexity**: O(1) - Constant space (output not counted)

## Key Insights
- Handles zeros by naturally producing zero products
- No division prevents precision issues
- Efficient for large arrays

## Alternative Approaches
1. **Prefix and Postfix arrays**: Use two arrays for left/right (O(n) space)
2. **Logarithms**: Use logs for multiplication (but handles zeros poorly)

## Solutions in Different Languages

### Java
```java
// ... code here ...
```

### JavaScript
```javascript
// ... code here ...
```

### Python
```python
# ... code here ...
```

## Test Cases
```
Test Case 1:
Input: [1,2,3,4]
Expected: [24,12,8,6]

Test Case 2:
Input: [-1,1,0,-3,3]
Expected: [0,0,9,0,0]
```

## Edge Cases
1. Array with zero
2. Array with multiple zeros
3. Array with negative numbers
4. Minimum length array (2 elements)
5. All elements same

## Follow-up Questions
1. What if division was allowed?
2. What if we need to handle very large numbers?
3. What if the array is empty?
