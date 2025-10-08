# Longest Consecutive Sequence - Problem #128

## Problem Statement
Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

## Examples
```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
```

## Approach
**Key Insight**: Use set to check sequences starting from numbers without predecessor.

**Algorithm**:
1. Put all nums in set
2. For each num, if num-1 not in set (start of sequence):
   - Count consecutive numbers
3. Track max length

**Why this works**:
- O(n) time (each num processed constant time)
- Skips non-starts
- Handles duplicates

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

## Key Insights
- Set for O(1) lookup
- Only start from sequence beginnings
- Linear time despite nested loop

## Alternative Approaches
1. **Sorting**: Sort and count (O(n log n))
2. **Union Find**: Overkill

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
Test Case 1: [100,4,200,1,3,2] -> 4
Test Case 2: [0,3,7,2,5,8,4,6,0,1] -> 9
```

## Edge Cases
1. Empty array
2. Single element
3. All duplicates
4. Negative numbers
5. Max length 1

## Follow-up Questions
1. What if find the sequence?
2. What if multiple longest?
3. What if not consecutive by 1?
