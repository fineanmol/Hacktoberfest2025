# Unique Paths - Problem #62

## Problem Statement
There is a robot on an `m x n` grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers `m` and `n`, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.

## Examples
```
Input: m = 3, n = 7
Output: 28

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Right -> Down
3. Down -> Down -> Right
```

## Approach
**Key Insight**: DP where dp[i][j] = number of ways to reach (i,j) = dp[i-1][j] + dp[i][j-1]

**Algorithm**:
1. Initialize m x n dp table
2. Set first row and first column to 1 (only one way)
3. For each cell (i,j): dp[i][j] = dp[i-1][j] + dp[i][j-1]
4. Return dp[m-1][n-1]

**Why this works**:
- Each cell sums ways from above and left
- O(m*n) time
- Handles grid paths

## Complexity Analysis
- **Time Complexity**: O(m*n)
- **Space Complexity**: O(m*n) - Can optimize to O(n)

## Key Insights
- Combinatorial: C(m+n-2, m-1)
- But DP for generalization
- No obstacles in this version

## Alternative Approaches
1. **Math**: Binomial coefficient
2. **1D DP**: Optimize space

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
Test Case 1: 3,7 -> 28
Test Case 2: 3,2 -> 3
```

## Edge Cases
1. 1x1 grid
2. 1xn or mx1
3. Large m,n (but per constraints)

## Follow-up Questions
1. What if obstacles?
2. What if diagonal moves?
3. What if find path count mod k?
