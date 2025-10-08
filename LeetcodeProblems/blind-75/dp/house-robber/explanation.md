# House Robber - Problem #198

## Problem Statement
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

## Examples
```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
```

## Approach
**Key Insight**: Dynamic programming: at each house, decide to rob (prev + current) or skip (current max).

**Algorithm**:
1. Base cases for 0 or 1 houses.
2. Use two variables: prev and curr.
3. For each house i >=2:
   temp = max(prev + nums[i], curr)
   prev = curr
   curr = temp
4. Return curr

**Why this works**:
- Avoids robbing adjacent
- O(n) time, O(1) space
- Bottom-up DP

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

## Key Insights
- Cannot rob adjacent
- Similar to max non-adjacent sum
- Space optimized

## Alternative Approaches
1. **DP Array**: O(n) space
2. **Recursion with Memo**

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
Test Case 1: [1,2,3,1] -> 4
Test Case 2: [2,7,9,3,1] -> 12
```

## Edge Cases
1. Empty array
2. Single house
3. Two houses
4. All zero

## Follow-up Questions
1. What if circular (House Robber II)?
2. What if tree structure?
3. What if multiple streets?
