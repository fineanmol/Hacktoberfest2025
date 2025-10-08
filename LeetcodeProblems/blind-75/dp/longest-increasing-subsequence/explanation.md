# Longest Increasing Subsequence - Problem #300

## Problem Statement
Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

## Examples
```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Input: nums = [0,1,0,3,2,3]
Output: 4
```

## Approach
**Key Insight**: Use patience sorting with binary search to maintain the smallest tails of all increasing subsequences.

**Algorithm**:
1. Initialize tails array
2. For each num, binary search for position in tails
3. If position == len(tails), append
4. Else, update tails[position] = num
5. Return len(tails)

**Why this works**:
- O(n log n) time
- tails[i] = smallest tail of all LIS with length i+1
- Binary search efficient

## Complexity Analysis
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(n)

## Key Insights
- Not the actual LIS, but length
- Patience sorting concept
- Handles duplicates (strictly increasing)

## Alternative Approaches
1. **DP**: O(n²) - dp[i] = max(dp[j]) +1 for j<i and nums[j]<nums[i]
2. **Recursion with Memo**: Top-down

## Solutions in Different Languages

### Java
```java
// ... code ...
```

### JavaScript
```javascript
// ... code ...
```

### Python
```python
# ... code ...
```

## Test Cases
```
Test Case 1: [10,9,2,5,3,7,101,18] -> 4
Test Case 2: [0,1,0,3,2,3] -> 4
```

## Edge Cases
1. Empty array
2. Single element
3. All increasing
4. All decreasing
5. Duplicates

## Follow-up Questions
1. What if find the LIS itself?
2. What if decreasing?
3. What if not strictly?
