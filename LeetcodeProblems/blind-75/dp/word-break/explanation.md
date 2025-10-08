# Word Break - Problem #139

## Problem Statement
Given a string `s` and a dictionary of strings `wordDict`, return true if `s` can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

## Examples
```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
```

## Approach
**Key Insight**: DP where dp[i] = true if s[0..i-1] can be segmented.

**Algorithm**:
1. dp[0] = true
2. For i=1 to len(s):
   For j=0 to i-1:
     If dp[j] and s[j:i] in wordDict, dp[i]=true
3. Return dp[len(s)]

**Why this works**:
- Checks all possible breaks
- O(n²) time
- Allows word reuse

## Complexity Analysis
- **Time Complexity**: O(n²)
- **Space Complexity**: O(n)

## Key Insights
- Like unbounded knapsack
- Set for fast lookup
- Bottom-up DP

## Alternative Approaches
1. **BFS**: Queue positions
2. **Memoization**: Top-down recursion

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
Test Case 1: "leetcode", ["leet","code"] -> true
Test Case 2: "applepenapple", ["apple","pen"] -> true
```

## Edge Cases
1. Empty s
2. Empty wordDict
3. s not breakable
4. Single word
5. Repeated words

## Follow-up Questions
1. What if find number of ways?
2. What if print segmentations?
3. What if word cost?
