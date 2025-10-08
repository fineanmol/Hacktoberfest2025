# Combination Sum - Problem #39

## Problem Statement
Given an array of distinct integers `candidates` and a target integer `target`, return a list of all unique combinations of `candidates` where the chosen numbers sum to `target`. You may return the combinations in any order.

The same number may be chosen from `candidates` an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to `target` is less than 150 combinations for the given input.

## Examples
```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
```

## Approach
**Key Insight**: Backtracking to explore all possible combinations.

**Algorithm**:
1. Define backtrack function with current list, remaining sum, start index
2. If remain == 0, add copy to result
3. If remain < 0, return
4. For i from start to len(candidates):
   - Add candidates[i] to temp
   - Recurse with remain - candidates[i], i (allow reuse)
   - Remove last from temp
5. Call backtrack with empty list, target, 0

**Why this works**:
- Explores all combinations
- Start index prevents duplicates
- Unlimited reuse by passing i

## Complexity Analysis
- **Time Complexity**: O(2^t) where t=target (worst case)
- **Space Complexity**: O(target) recursion depth

## Key Insights
- Backtracking for combinations
- Reuse allowed (unbounded)
- Sorted candidates can optimize

## Alternative Approaches
1. **DP**: Build combinations bottom-up
2. **Memoization**: Cache subproblems

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
Test Case 1: [2,3,6,7], 7 -> [[2,2,3],[7]]
Test Case 2: [2,3,5], 8 -> [[2,2,2,2],[2,3,3],[3,5]]
```

## Edge Cases
1. Target=0
2. Empty candidates
3. No combination
4. Single candidate
5. Target smaller than min

## Follow-up Questions
1. What if no reuse?
2. What if find number of combinations?
3. What if duplicates in candidates?
