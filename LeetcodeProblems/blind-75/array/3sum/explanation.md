# 3Sum - Problem #15

## Problem Statement
Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

## Examples
```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Input: nums = [0,1,1]
Output: []
```

## Approach
**Key Insight**: Sort the array and use two pointers to find triplets.

**Algorithm**:
1. Sort the array.
2. Fix i, then use left and right pointers for j and k.
3. If sum == 0, add triplet and skip duplicates.
4. Adjust pointers based on sum >0 or <0.
5. Skip duplicates for i.

**Why this works**:
- Sorting allows efficient duplicate skipping
- O(n²) time
- Prevents duplicate triplets

## Complexity Analysis
- **Time Complexity**: O(n²) - For loop + two pointers
- **Space Complexity**: O(1) - Excluding output

## Key Insights
- Sorting is crucial for efficiency
- Duplicate skipping prevents duplicates
- Handles negatives and zeros

## Alternative Approaches
1. **Hash Set**: For each pair, check complement (O(n²) space)
2. **Brute Force**: Three loops (O(n³))

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
Input: [-1,0,1,2,-1,-4]
Expected: [[-1,-1,2],[-1,0,1]]
```

## Edge Cases
1. All zeros
2. No triplets
3. Duplicates
4. Small array
5. Large numbers

## Follow-up Questions
1. What if find all quadruplets?
2. What if sum to target !=0?
3. What if allow duplicates?
