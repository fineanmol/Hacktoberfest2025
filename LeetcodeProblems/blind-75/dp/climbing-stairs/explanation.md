# Climbing Stairs - Problem #70

## Problem Statement
You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

## Examples
```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

## Approach
**Key Insight**: This is a classic dynamic programming problem similar to Fibonacci sequence.

**Algorithm**:
1. Base cases: dp[1] = 1, dp[2] = 2
2. For i from 3 to n: dp[i] = dp[i-1] + dp[i-2]
3. Return dp[n]

**Why this works**:
- Each step can be reached from previous 1 or 2 steps
- O(n) time and space
- Bottom-up DP

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(n) - Can optimize to O(1)

## Key Insights
- Fibonacci sequence shifted
- Can optimize space with variables
- Handles small n with base cases

## Alternative Approaches
1. **Recursion with Memoization**: Top-down DP
2. **Matrix Exponentiation**: O(log n) time
3. **Math Formula**: Binet's formula

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
Test Case 1: 2 -> 2
Test Case 2: 3 -> 3
Test Case 3: 1 -> 1
```

## Edge Cases
1. n=0
2. n=1
3. n=2
4. Large n (45 max per constraints)

## Follow-up Questions
1. What if 3 steps allowed?
2. What if cost per step?
3. What if obstacles?
