# Set Matrix Zeroes - Problem #73

## Problem Statement
Given an `m x n` integer matrix `matrix`, if an element is 0, set its entire row and column to 0's.

You must do it in place.

## Examples
```
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

## Approach
**Key Insight**: Use first row and column as markers for zeros, with flags for them.

**Algorithm**:
1. Check if first row/col has zeros, set flags
2. Mark zeros in first row/col for inner matrix
3. Set inner matrix zeros based on marks
4. Set first row/col to zero if flags set

**Why this works**:
- O(1) extra space
- O(m*n) time
- In-place

## Complexity Analysis
- **Time Complexity**: O(m*n)
- **Space Complexity**: O(1)

## Key Insights
- Use matrix itself for storage
- Handle first row/col separately
- Avoid premature zeroing

## Alternative Approaches
1. **O(m+n) Space**: Sets for rows/cols
2. **O(m*n) Time**: Copy matrix

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
Test Case 1: [[1,1,1],[1,0,1],[1,1,1]] -> [[1,0,1],[0,0,0],[1,0,1]]
Test Case 2: [[0,1,2,0],[3,4,5,2],[1,3,1,5]] -> [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

## Edge Cases
1. Empty matrix
2. 1x1 with 0
3. 1x1 with 1
4. All zeros
5. Zero in first row/col

## Follow-up Questions
1. What if set to another value?
2. What if 3D matrix?
3. What if sparse matrix?
