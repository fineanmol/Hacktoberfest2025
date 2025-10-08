# Clone Graph - Problem #133

## Problem Statement
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

## Test case format:
For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

## Examples
```
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
```

## Approach
**Key Insight**: Use DFS with a map to track cloned nodes and avoid cycles.

**Algorithm**:
1. If node is null, return null
2. Use a map to store original to clone
3. DFS: If visited, return clone
4. Create new clone, add to map
5. Recurse on neighbors, add to clone's neighbors
6. Return clone

**Why this works**:
- Handles cycles with visited map
- O(V+E) time
- Deep copy

## Complexity Analysis
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V)

## Key Insights
- Graph cloning needs cycle handling
- DFS or BFS both work
- Map for original to clone

## Alternative Approaches
1. **BFS**: Queue based cloning
2. **Recursive Copy**

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
Test Case 1: [[2,4],[1,3],[2,4],[1,3]] -> clone
Test Case 2: [[]] -> clone single node
```

## Edge Cases
1. Empty graph
2. Single node
3. Disconnected (but problem says connected)
4. Cycles

## Follow-up Questions
1. What if directed graph?
2. What if weighted edges?
3. What if clone structure only?
