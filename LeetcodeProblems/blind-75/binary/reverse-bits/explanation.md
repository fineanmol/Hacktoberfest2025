# Reverse Bits - Problem #190

## Problem Statement
Reverse the bits of a given 32 bits unsigned integer.

Note:
- In some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
- In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.

## Examples
```
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
```

## Approach
**Key Insight**: Shift bits one by one to reverse the order.

**Algorithm**:
1. Initialize result = 0
2. For 32 times:
   - Left shift result
   - Add the least significant bit of n to result
   - Right shift n
3. Return result

**Why this works**:
- Builds the reverse bit by bit
- O(1) time (fixed 32 iterations)
- Handles unsigned nature

## Complexity Analysis
- **Time Complexity**: O(1) - Fixed loop
- **Space Complexity**: O(1)

## Key Insights
- Use unsigned shift in JS
- Python handles large ints naturally
- Important for bit manipulation

## Alternative Approaches
1. **Bitwise Tricks**: Swap bits in pairs
2. **Lookup Table**: For faster but more space

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
Test Case 1: 43261596 -> 964176192
Test Case 2: 4294967293 -> 3221225471
```

## Edge Cases
1. All zeros
2. All ones
3. Alternating bits
4. Single bit set

## Follow-up Questions
1. What if 64 bits?
2. What if reverse bytes?
3. What if count leading zeros?
