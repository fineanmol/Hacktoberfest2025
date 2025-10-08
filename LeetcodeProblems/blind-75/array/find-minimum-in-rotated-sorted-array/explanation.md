# Find Minimum in Rotated Sorted Array - Problem #153

## Problem Statement
Suppose an array of length `n` sorted in ascending order is rotated between 1 and `n` times.

Given the sorted rotated array `nums` of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

## Examples
```
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
```

## Approach
**Key Insight**: Use binary search to find the rotation point where the minimum is located.

**Algorithm**:
1. Set left to 0 and right to n-1.
2. While left < right:
   - Calculate mid.
   - If nums[mid] > nums[right], minimum is in right half (left = mid + 1)
   - Else, minimum is in left half or at mid (right = mid)
3. Return nums[left]

**Why this works**:
- O(log n) time via binary search
- Exploits the sorted rotated property
- Handles no rotation case

## Complexity Analysis
- **Time Complexity**: O(log n) - Binary search
- **Space Complexity**: O(1) - Constant space

## Key Insights
- The minimum is where the rotation happens
- Compare mid with right to determine which half
- Works because array is sorted and unique

## Alternative Approaches
1. **Linear Scan**: O(n) time
2. **Find Rotation Index**: Similar binary search

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
Input: [3,4,5,1,2]
Expected: 1

Test Case 2:
Input: [4,5,6,7,0,1,2]
Expected: 0
```

## Edge Cases
1. No rotation
2. Rotated once
3. All elements rotated
4. Two elements
5. Single element

## Follow-up Questions
1. What if duplicates allowed?
2. What if find maximum?
3. What if array not rotated?
