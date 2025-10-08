# Sum of Two Integers - Problem #371

## Problem Statement
Given two integers `a` and `b`, return the sum of `a` and `b` without using the operators `+` and `-`.

## Examples
```
Input: a = 1, b = 2
Output: 3

Input: a = 2, b = 3
Output: 5
```

## Approach
**Key Insight**: Use bitwise operations to simulate addition.

**Algorithm**:
1. XOR (^) for addition without carry.
2. AND (&) and left shift (<<) for carry.
3. Repeat until no carry.

**Why this works**:
- Mimics binary addition
- O(1) time (32 bits)
- Handles positive numbers

Note: Python handles unbounded integers, needs mask for 32-bit.

## Complexity Analysis
- **Time Complexity**: O(1) - Fixed operations
- **Space Complexity**: O(1)

## Key Insights
- XOR adds bits
- Carry is AND shifted left
- Loop until carry zero

## Alternative Approaches
1. **Recursion**: Recursive carry
2. **Bit Manipulation Tricks**

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
Test Case 1: 1, 2 -> 3
Test Case 2: 2, 3 -> 5
```

## Edge Cases
1. Negative numbers
2. Zero
3. Max int
4. Min int

## Follow-up Questions
1. What if subtract?
2. What if multiply?
3. What if divide?
