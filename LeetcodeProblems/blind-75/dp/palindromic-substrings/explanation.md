# Palindromic Substrings - Problem #647

## Problem Statement
Given a string `s`, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

## Examples
```
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

## Approach
**Key Insight**: Expand around each possible center for odd and even length palindromes.

**Algorithm**:
1. For each index i:
   - Expand for odd length (center i)
   - Expand for even length (center i, i+1)
2. Count each valid palindrome found

**Why this works**:
- Covers all possible palindromes
- O(n²) time
- Efficient for counting

## Complexity Analysis
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)

## Key Insights
- 2n-1 possible centers (n odd + n-1 even)
- Expand while characters match
- Counts single chars automatically

## Alternative Approaches
1. **DP Table**: dp[i][j] = is palindrome
2. **Manacher's Algorithm**: O(n) time (advanced)

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
Test Case 1: "abc" -> 3
Test Case 2: "aaa" -> 6
```

## Edge Cases
1. Empty string
2. Single char
3. All same chars
4. Alternating chars

## Follow-up Questions
1. What if longest palindrome?
2. What if non-contiguous?
3. What if case insensitive?
