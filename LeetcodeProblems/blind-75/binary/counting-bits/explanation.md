# Counting Bits - Problem #338

## Problem Statement
Given an integer `n`, return an array `ans` of length `n + 1` such that for each `i` (0 <= i <= n), `ans[i]` is the number of 1's in the binary representation of `i`.

## Examples
```
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Input: n = 5
Output: [0,1,1,2,1,2]
```

## Approach
**Key Insight**: Use dynamic programming: number of 1s in i is number of 1s in i/2 plus the least significant bit.

**Algorithm**:
1. Initialize dp[0] = 0
2. For i from 1 to n:
   dp[i] = dp[i >> 1] + (i & 1)
3. Return dp

**Why this works**:
- O(n) time
- Reuses computation from smaller numbers
- Efficient bit manipulation

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

## Key Insights
- i >> 1 is i // 2
- i & 1 gives LSB
- Builds bottom-up

## Alternative Approaches
1. **Built-in**: bin(i).count('1') - O(n log n)
2. **Loop per number**: Count bits each time - O(n log n)

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
Test Case 1: 2 -> [0,1,1]
Test Case 2: 5 -> [0,1,1,2,1,2]
```

## Edge Cases
1. n=0
2. n=1
3. Large n (2^31 -1)

## Follow-up Questions
1. What if count 0s?
2. What if for range?
3. What if parity?
