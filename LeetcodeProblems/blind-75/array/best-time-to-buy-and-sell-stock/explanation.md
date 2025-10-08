# Best Time to Buy and Sell Stock - Problem #121

## Problem Statement
You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

## Examples
```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

## Approach
**Key Insight**: Track the minimum price seen so far and the maximum profit achievable.

**Algorithm**:
1. Initialize `minPrice` to a large number and `maxProfit` to 0.
2. Iterate through the prices array.
3. Update `minPrice` if a lower price is found.
4. Calculate potential profit (current price - minPrice) and update `maxProfit` if higher.

**Why this works**:
- One pass through the array (O(n) time)
- Always buys at the lowest price seen before selling
- Handles cases where prices only decrease

## Complexity Analysis
- **Time Complexity**: O(n) - Single pass through the array
- **Space Complexity**: O(1) - Constant space

## Key Insights
- We only need to track the minimum price so far
- Profit is calculated as we go, no need for two pointers
- Works because we can only buy once and sell once

## Alternative Approaches
1. **Brute Force**: Check all possible buy/sell pairs (O(n²) time)
2. **Dynamic Programming**: Track profit states (more complex for this problem)

## Solutions in Different Languages

### Java
```java
// Best Time to Buy and Sell Stock - LeetCode #121

class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE;
        int maxProfit = 0;
        
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }
        
        return maxProfit;
    }
}
```

### JavaScript
```javascript
// Best Time to Buy and Sell Stock - LeetCode #121

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let minPrice = Infinity;
    let maxProfit = 0;
    
    for (let price of prices) {
        if (price < minPrice) {
            minPrice = price;
        } else if (price - minPrice > maxProfit) {
            maxProfit = price - minPrice;
        }
    }
    
    return maxProfit;
};
```

### Python
```python
# Best Time to Buy and Sell Stock - LeetCode #121

from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = float('inf')
        max_profit = 0
        
        for price in prices:
            if price < min_price:
                min_price = price
            elif price - min_price > max_profit:
                max_profit = price - min_price
        
        return max_profit
```

## Test Cases
```
Test Case 1:
Input: [7,1,5,3,6,4]
Expected Output: 5

Test Case 2:
Input: [7,6,4,3,1]
Expected Output: 0

Test Case 3:
Input: [1,2]
Expected Output: 1

Test Case 4:
Input: [2,1]
Expected Output: 0
```

## Edge Cases
1. Empty array
2. Array with one element
3. All prices equal
4. Prices in increasing order
5. Prices in decreasing order

## Follow-up Questions
1. What if we can buy and sell multiple times?
2. What if there is a transaction fee?
3. What if we can hold multiple stocks?
4. What if we have a cooldown period?
