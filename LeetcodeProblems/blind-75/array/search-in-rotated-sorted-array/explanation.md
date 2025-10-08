# Search in Rotated Sorted Array - Problem #33

## Problem Statement
There is an integer array `nums` sorted in ascending order (with distinct values).

Prior to being passed to your function, `nums` is possibly rotated at an unknown pivot index `k` (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array `nums` after the possible rotation and an integer `target`, return the index of `target` if it is in `nums`, or -1 if it is not in `nums`.

You must write an algorithm with O(log n) runtime complexity.

## Examples
```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

## Approach
**Key Insight**: Modified binary search that determines which half is sorted.

**Algorithm**:
1. Set left=0, right=n-1
2. While left <= right:
   - Calculate mid
   - If nums[mid] == target, return mid
   - If left half sorted:
     - If target in left half, search left
     - Else search right
   - Else right half sorted:
     - If target in right half, search right
     - Else search left
3. Return -1

**Why this works**:
- O(log n) time
- Handles rotation by checking sorted half
- Works for non-rotated arrays too

## Complexity Analysis
- **Time Complexity**: O(log n) - Binary search
- **Space Complexity**: O(1)

## Key Insights
- One half is always sorted
- Compare mid with left/right to find sorted half
- Assumes unique elements

## Alternative Approaches
1. **Find Pivot + Binary Search**: First find min, then search
2. **Linear Search**: O(n) time (not optimal)

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
Input: [4,5,6,7,0,1,2], 0
Expected: 4

Test Case 2:
Input: [4,5,6,7,0,1,2], 3
Expected: -1
```

## Edge Cases
1. No rotation
2. Target at pivot
3. Target not present
4. Single element
5. Two elements

## Follow-up Questions
1. What if duplicates?
2. What if find all occurrences?
3. What if multiple rotations?
