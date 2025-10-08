# Number of 1 Bits - Problem #191

## Problem Statement
Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:
- Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
- In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.

## Examples
```
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
```

## Approach
**Key Insight**: Use bitwise AND and right shift to count set bits.

**Algorithm**:
1. Initialize count = 0
2. While n != 0:
   - count += n & 1 (check if least significant bit is 1)
   - n >>>= 1 (unsigned right shift)
3. Return count

**Why this works**:
- Checks each bit individually
- O(1) time (32 bits)
- Handles signed/unsigned

## Complexity Analysis
- **Time Complexity**: O(1) - Fixed 32 iterations
- **Space Complexity**: O(1)

## Key Insights
- Use unsigned shift in Java
- n & (n-1) trick for optimization
- Built-in functions available

## Alternative Approaches
1. **Bit Trick**: while(n){n &= (n-1); count++;}
2. **Built-in**: Integer.bitCount(n) in Java

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
Test Case 1: 11 -> 3
Test Case 2: 128 -> 1
```

## Edge Cases
1. n = 0
2. All bits set
3. Negative (in signed)
4. Max value

## Follow-up Questions
1. What if count 0 bits?
2. What if for 64-bit?
3. What if parity check?
