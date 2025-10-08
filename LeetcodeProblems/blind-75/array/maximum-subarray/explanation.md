# Maximum Subarray - Problem #53

## Problem Statement
Given an integer array `nums`, find the subarray (containing at least one number) which has the largest sum and return its sum.

A **subarray** is a contiguous part of an array.

## Examples
```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```

## Approach
**Key Insight**: Use Kadane's algorithm to find the maximum subarray sum in linear time.

**Algorithm**:
1. Initialize two variables: `maxCurrent` and `maxGlobal` to the first element.
2. For each subsequent element:
   - Update `maxCurrent` to max(current element, maxCurrent + current element)
   - If `maxCurrent` > `maxGlobal`, update `maxGlobal`
3. Return `maxGlobal`

**Why this works**:
- Handles negative numbers by restarting subarray when sum becomes negative
- O(n) time complexity
- Works for all positive and mixed sign arrays

## Complexity Analysis
- **Time Complexity**: O(n) - Single pass
- **Space Complexity**: O(1) - Constant space

## Key Insights
- Resets sum when it becomes negative
- Handles all negative arrays (returns least negative)
- Dynamic programming bottom-up approach

## Alternative Approaches
1. **Brute Force**: Check all subarrays (O(n²) time)
2. **Divide and Conquer**: Recursive split (O(n log n) time)

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
Input: [-2,1,-3,4,-1,2,1,-5,4]
Expected: 6

Test Case 2:
Input: [5,4,-1,7,8]
Expected: 23

Test Case 3:
Input: [-1]
Expected: -1
```

## Edge Cases
1. Single element array
2. All negative numbers
3. All positive numbers
4. Array with zeros
5. Empty array (though not per problem)

## Follow-up Questions
1. What if we need the subarray indices?
2. What if we need k maximum subarrays?
3. What if the array is circular?
