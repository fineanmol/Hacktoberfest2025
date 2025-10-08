# Number of Islands - Problem #200

## Problem Statement
Given an `m x n` 2D binary grid `grid` which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

## Examples
```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

## Approach
**Key Insight**: Use DFS to traverse and mark connected '1's as visited.

**Algorithm**:
1. Iterate through each cell
2. If '1', perform DFS to mark all connected '1's to '0'
3. Increment count for each new island
4. DFS explores 4 directions

**Why this works**:
- Visits each cell once
- O(m*n) time
- Modifies grid to mark visited

## Complexity Analysis
- **Time Complexity**: O(m*n)
- **Space Complexity**: O(m*n) recursion stack worst case

## Key Insights
- Graph traversal on grid
- 4-direction DFS
- Modify grid to avoid visited array

## Alternative Approaches
1. **BFS**: Queue based
2. **Union Find**: For connected components

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
Test Case 1: Above grid -> 1
Test Case 2: Above grid -> 3
```

## Edge Cases
1. Empty grid
2. All water
3. All land
4. Single cell
5. Checkerboard

## Follow-up Questions
1. What if count island perimeter?
2. What if 8 directions?
3. What if weighted lands?
