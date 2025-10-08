# Word Search

## Problem Statement
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

## Examples

### Example 1:
```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```

### Example 2:
```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```

### Example 3:
```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
```

## Approach

### Method: Backtracking with DFS
**Key Insight**: Use depth-first search with backtracking to explore all possible paths in the grid.

**Steps**:
1. Iterate through each cell in the grid as a potential starting point
2. For each starting cell, perform DFS to find the word
3. Use backtracking to mark visited cells and restore them after exploration
4. Return true if any path leads to the complete word

**Time Complexity**: O(m × n × 4^L) where L is the length of the word
**Space Complexity**: O(L) for the recursion stack

## Solution Code

### Java
```java
class Solution {
    private boolean[][] visited;
    private int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        visited = new boolean[m][n];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    private boolean dfs(char[][] board, String word, int i, int j, int index) {
        if (index == word.length()) {
            return true;
        }
        
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || 
            visited[i][j] || board[i][j] != word.charAt(index)) {
            return false;
        }
        
        visited[i][j] = true;
        
        for (int[] dir : directions) {
            if (dfs(board, word, i + dir[0], j + dir[1], index + 1)) {
                return true;
            }
        }
        
        visited[i][j] = false;
        return false;
    }
}
```

### JavaScript
```javascript
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    const m = board.length;
    const n = board[0].length;
    const visited = Array(m).fill().map(() => Array(n).fill(false));
    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    
    function dfs(i, j, index) {
        if (index === word.length) {
            return true;
        }
        
        if (i < 0 || i >= m || j < 0 || j >= n || 
            visited[i][j] || board[i][j] !== word[index]) {
            return false;
        }
        
        visited[i][j] = true;
        
        for (const [di, dj] of directions) {
            if (dfs(i + di, j + dj, index + 1)) {
                return true;
            }
        }
        
        visited[i][j] = false;
        return false;
    }
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (dfs(i, j, 0)) {
                return true;
            }
        }
    }
    
    return false;
};
```

### Python
```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        visited = [[False] * n for _ in range(m)]
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        def dfs(i, j, index):
            if index == len(word):
                return True
            
            if (i < 0 or i >= m or j < 0 or j >= n or 
                visited[i][j] or board[i][j] != word[index]):
                return False
            
            visited[i][j] = True
            
            for di, dj in directions:
                if dfs(i + di, j + dj, index + 1):
                    return True
            
            visited[i][j] = False
            return False
        
        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        
        return False
```

## Key Insights

1. **Backtracking**: Mark cells as visited and restore them after exploration
2. **DFS**: Explore all four directions from each cell
3. **Early termination**: Return true as soon as the word is found
4. **Boundary checking**: Ensure we don't go out of bounds
5. **Character matching**: Check if current cell matches the expected character

## Test Cases

### Test Case 1: Word exists
```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```

### Test Case 2: Word doesn't exist
```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
```

### Test Case 3: Single character
```
Input: board = [["A"]], word = "A"
Output: true
```

### Test Case 4: Empty word
```
Input: board = [["A","B"],["C","D"]], word = ""
Output: true
```

## Follow-up Questions

1. What if we need to find all occurrences of the word?
2. What if we can use diagonal movements as well?
3. What if the board is very large and we need to optimize?
4. What if we need to find multiple words efficiently?
