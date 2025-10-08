# Word Search - Problem #79

## Problem Statement
Given an `m x n` grid of characters `board` and a string `word`, return true if `word` exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

## Examples
```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```

## Approach
**Key Insight**: Backtracking DFS from each cell, marking visited.

**Algorithm**:
1. For each cell, if matches word[0], start DFS
2. DFS: Check bounds, match, not visited
3. Mark visited, recurse 4 directions
4. Backtrack unmark
5. If reach word length, return true

**Why this works**:
- Explores all paths
- O(m*n*4^len(word)) worst
- Prevents reuse with marking

## Complexity Analysis
- **Time Complexity**: O(m*n*3^l) l=word len
- **Space Complexity**: O(l) recursion

## Key Insights
- Grid as graph
- Backtracking for path finding
- Modify board for visited

## Alternative Approaches
1. **BFS**: Less efficient
2. **Separate visited matrix**

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
Test Case 1: Above, "ABCCED" -> true
Test Case 2: Above, "SEE" -> true
```

## Edge Cases
1. Word longer than board
2. Word with repeats
3. Board with one cell
4. Empty word/board

## Follow-up Questions
1. What if diagonals allowed?
2. What if multiple words?
3. What if find all occurrences?
