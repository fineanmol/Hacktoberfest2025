# House Robber II - Problem #213

## Problem Statement
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

## Examples
```
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

## Approach
**Key Insight**: Handle circular by computing max of two linear cases: without first and without last.

**Algorithm**:
1. If n==0 return 0, n==1 return nums[0]
2. Compute rob linear from 0 to n-2 (exclude last)
3. Compute rob linear from 1 to n-1 (exclude first)
4. Return max of the two
5. Linear rob uses O(1) space DP

**Why this works**:
- Avoids robbing first and last together
- O(n) time
- Reuses linear robber logic

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

## Key Insights
- Circular constraint handled by two cases
- Same as House Robber but with exclusion
- Optimize space with variables

## Alternative Approaches
1. **DP with states**: Include first/last choice
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
Test Case 1: [2,3,2] -> 3
Test Case 2: [1,2,3,1] -> 4
```

## Edge Cases
1. Empty array
2. Single house
3. Two houses
4. All equal

## Follow-up Questions
1. What if tree structure?
2. What if multiple constraints?
3. What if costs for robbing?
