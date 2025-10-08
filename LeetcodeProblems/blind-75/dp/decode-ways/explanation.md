# Decode Ways - Problem #91

## Problem Statement
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string `s` containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

## Examples
```
Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
```

## Approach
**Key Insight**: DP where dp[i] = number of ways to decode first i characters.

**Algorithm**:
1. dp[0] = 1, dp[1] = 1 if s[0] != '0' else 0
2. For i=2 to n:
   - If one_digit (s[i-1]) valid, add dp[i-1]
   - If two_digits (s[i-2:i]) valid, add dp[i-2]
3. Return dp[n]

**Why this works**:
- Handles '0' cases properly
- O(n) time
- Checks 1 and 2 digit decodings

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(n) - Can optimize to O(1)

## Key Insights
- '0' can only be part of '10' or '20'
- No leading zeros in decodings
- Similar to climbing stairs

## Alternative Approaches
1. **Recursion with Memo**: Top-down
2. **O(1) Space DP**: Use variables

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
Test Case 1: "12" -> 2
Test Case 2: "226" -> 3
```

## Edge Cases
1. Starts with '0'
2. Contains '0'
3. Empty string
4. Single digit
5. Invalid like '30'

## Follow-up Questions
1. What if decode to letters?
2. What if 3-digit codes?
3. What if count invalid ways?
