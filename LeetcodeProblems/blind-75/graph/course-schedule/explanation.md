# Course Schedule - Problem #207

## Problem Statement
There are a total of `numCourses` courses you have to take, labeled from 0 to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you must take course `bi` first if you want to take course `ai`.

- For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return `true` if you can finish all courses. Otherwise, return `false`.

## Examples
```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
```

## Approach
**Key Insight**: Detect if graph has cycle using topological sort (Kahn's algorithm).

**Algorithm**:
1. Build graph and indegree array
2. Queue all nodes with indegree 0
3. BFS: Reduce indegrees of neighbors
4. If processed nodes == numCourses, no cycle (true)
5. Else, cycle exists (false)

**Why this works**:
- Cycle prevents topological sort
- O(V + E) time
- Detects if DAG

## Complexity Analysis
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V + E)

## Key Insights
- Course prereqs as directed graph
- Cycle means impossible
- Toposort for cycle detection

## Alternative Approaches
1. **DFS with Colors**: Detect cycle
2. **Union Find**: Less suitable

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
Test Case 1: 2, [[1,0]] -> true
Test Case 2: 2, [[1,0],[0,1]] -> false
```

## Edge Cases
1. No prerequisites
2. Single course
3. Disconnected graph
4. Self-loop (invalid per problem)

## Follow-up Questions
1. What if find order (Course Schedule II)?
2. What if multiple prereqs?
3. What if minimum time?
