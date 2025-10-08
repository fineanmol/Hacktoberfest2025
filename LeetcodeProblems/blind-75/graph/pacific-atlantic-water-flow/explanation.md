# Pacific Atlantic Water Flow - Problem #417

## Problem Statement
There is an `m x n` rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an `m x n` integer matrix `heights` where `heights[r][c]` represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates `result` where `result[i] = [ri, ci]` denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

## Examples
```
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
```

## Approach
**Key Insight**: DFS from ocean borders, mark reachable cells for Pacific and Atlantic, find intersection.

**Algorithm**:
1. Create two visited matrices for Pacific and Atlantic
2. DFS from left/top for Pacific, right/bottom for Atlantic
3. DFS condition: neighbor >= current height
4. Collect cells reachable from both

**Why this works**:
- Reverse flow from oceans (since water flows to <= height)
- O(m*n) time
- Finds multi-source reachable

## Complexity Analysis
- **Time Complexity**: O(m*n)
- **Space Complexity**: O(m*n)

## Key Insights
- Reverse thinking: flow to ocean = reachable from ocean
- DFS from borders
- Handles equal heights

## Alternative Approaches
1. **BFS**: Queue based
2. **Union Find**: Connect to oceans

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
Test Case 1: Above heights -> [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
```

## Edge Cases
1. 1x1 grid
2. All same height
3. Increasing heights
4. Empty grid

## Follow-up Questions
1. What if flow only < height?
2. What if 3 oceans?
3. What if find flow path?
