# Longest Common Subsequence - Problem #1143

## Problem Statement
Given two strings `text1` and `text2`, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

A common subsequence of two strings is a subsequence that is common to both strings.

## Examples
```
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
```

## Approach
**Key Insight**: Use 2D DP where dp[i][j] = LCS of first i chars of text1 and j of text2.

**Algorithm**:
1. Initialize (m+1) x (n+1) dp table to 0
2. For each i in 1 to m:
   For each j in 1 to n:
     If text1[i-1] == text2[j-1]: dp[i][j] = dp[i-1][j-1] + 1
     Else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
3. Return dp[m][n]

**Why this works**:
- Bottom-up DP
- O(m*n) time
- Handles non-contiguous subsequences

## Complexity Analysis
- **Time Complexity**: O(m*n)
- **Space Complexity**: O(m*n) - Can optimize to O(min(m,n))

## Key Insights
- Not substring, subsequence (non-contiguous)
- Diagonal increment when match
- Max from left/top when no match

## Alternative Approaches
1. **Recursion with Memo**: Top-down
2. **1D DP**: Space optimization

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
Test Case 1: "abcde", "ace" -> 3
Test Case 2: "abc", "def" -> 0
```

## Edge Cases
1. Empty strings
2. One empty
3. Identical strings
4. No common chars
5. All same char

## Follow-up Questions
1. What if find the LCS string?
2. What if longest common substring?
3. What if multiple strings?
