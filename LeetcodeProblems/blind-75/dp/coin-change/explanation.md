# Coin Change - Problem #322

## Problem Statement
You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

## Examples
```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Input: coins = [2], amount = 3
Output: -1
```

## Approach
**Key Insight**: Unbounded knapsack DP to find minimum coins.

**Algorithm**:
1. dp[i] = min coins for amount i
2. Initialize dp[0]=0, others=INF
3. For each coin, update dp for amounts >= coin
4. Return dp[amount] if not INF else -1

**Why this works**:
- Bottom-up DP
- O(amount * coins) time
- Handles unlimited coins

## Complexity Analysis
- **Time Complexity**: O(amount * coins.length)
- **Space Complexity**: O(amount)

## Key Insights
- Like unbounded knapsack
- Order of loops important
- Handles no solution case

## Alternative Approaches
1. **DFS with Memo**: Top-down
2. **BFS**: Level order search

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
Test Case 1: [1,2,5], 11 -> 3
Test Case 2: [2], 3 -> -1
```

## Edge Cases
1. amount=0
2. No coins
3. Amount not makeable
4. Single coin

## Follow-up Questions
1. What if limited coins?
2. What if find number of ways?
3. What if print combination?
