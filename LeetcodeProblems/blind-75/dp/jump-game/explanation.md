# Jump Game - Problem #55

## Problem Statement
You are given an integer array `nums`. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

## Examples
```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
```

## Approach
**Key Insight**: Greedy - track the farthest you can reach.

**Algorithm**:
1. Initialize maxReach = 0
2. For each i from 0 to n-1:
   - If i > maxReach, return false
   - Update maxReach = max(maxReach, i + nums[i])
   - If maxReach >= n-1, return true
3. Return true

**Why this works**:
- O(n) time
- Checks if current position reachable
- Updates farthest possible

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

## Key Insights
- Greedy better than DP for this
- Early termination possible
- Handles zeros as barriers

## Alternative Approaches
1. **DP**: dp[i] = can reach i (O(n²) worst)
2. **BFS**: Treat as graph (O(n))

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
Test Case 1: [2,3,1,1,4] -> true
Test Case 2: [3,2,1,0,4] -> false
```

## Edge Cases
1. Single element
2. All zeros except first
3. Can jump beyond end
4. Minimum jumps

## Follow-up Questions
1. What if find minimum jumps (Jump Game II)?
2. What if backward jumps?
3. What if obstacles?
