# Rotate Image

## Problem Statement
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

## Examples

### Example 1:
```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```

### Example 2:
```
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

## Approach

### Method 1: Transpose + Reverse (Recommended)
**Key Insight**: A 90-degree clockwise rotation can be achieved by:
1. Transposing the matrix (swap rows and columns)
2. Reversing each row

**Steps**:
1. Transpose the matrix: `matrix[i][j] = matrix[j][i]` for all i < j
2. Reverse each row of the transposed matrix

**Time Complexity**: O(n²)
**Space Complexity**: O(1)

### Method 2: Layer by Layer Rotation
**Key Insight**: Rotate the matrix layer by layer, starting from the outermost layer.

**Steps**:
1. For each layer (from outer to inner)
2. Rotate 4 elements at a time in a cycle
3. Move to the next layer

**Time Complexity**: O(n²)
**Space Complexity**: O(1)

## Solution Code

### Java
```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        
        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // Reverse each row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = temp;
            }
        }
    }
}
```

### JavaScript
```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    const n = matrix.length;
    
    // Transpose the matrix
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
        }
    }
    
    // Reverse each row
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < Math.floor(n / 2); j++) {
            [matrix[i][j], matrix[i][n - 1 - j]] = [matrix[i][n - 1 - j], matrix[i][j]];
        }
    }
};
```

### Python
```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        
        # Transpose the matrix
        for i in range(n):
            for j in range(i, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        # Reverse each row
        for i in range(n):
            for j in range(n // 2):
                matrix[i][j], matrix[i][n - 1 - j] = matrix[i][n - 1 - j], matrix[i][j]
```

## Key Insights

1. **Transpose + Reverse**: The most elegant solution that's easy to understand and implement
2. **In-place modification**: No extra space needed, just swap elements
3. **Layer rotation**: Alternative approach that rotates elements in cycles
4. **Matrix properties**: Understanding how rotation affects element positions

## Test Cases

### Test Case 1: 2x2 Matrix
```
Input: [[1,2],[3,4]]
Output: [[3,1],[4,2]]
```

### Test Case 2: 3x3 Matrix
```
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```

### Test Case 3: 4x4 Matrix
```
Input: [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

### Test Case 4: 1x1 Matrix
```
Input: [[1]]
Output: [[1]]
```

## Follow-up Questions

1. What if we need to rotate by 180 degrees?
2. What if we need to rotate by 270 degrees (counter-clockwise)?
3. What if the matrix is not square?
4. What if we need to rotate by an arbitrary angle?
