# Missing Number - Problem #268

## Problem Statement
Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

## Examples
```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```

## Approach
**Key Insight**: Use XOR to find the missing number by XORing all expected and actual numbers.

**Algorithm**:
1. Initialize xor = 0
2. XOR all numbers from 0 to n
3. XOR all numbers in nums
4. The result is the missing number

**Why this works**:
- XOR is its own inverse (a ^ a = 0, 0 ^ b = b)
- All present numbers cancel out
- O(n) time, O(1) space

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

## Key Insights
- XOR cancels duplicates
- Range [0,n] means n+1 elements expected
- Handles 0 properly

## Alternative Approaches
1. **Sum Formula**: expected sum - actual sum
2. **Sorting**: Sort and check missing
3. **Hash Set**: Track seen numbers

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
Test Case 1: [3,0,1] -> 2
Test Case 2: [0,1] -> 2
Test Case 3: [9,6,4,2,3,5,7,0,1] -> 8
```

## Edge Cases
1. Missing 0
2. Missing n
3. n=0
4. n=1

## Follow-up Questions
1. What if multiple missing?
2. What if duplicates?
3. What if range not [0,n]?
