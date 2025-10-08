# Merge k Sorted Lists - Problem #23

## Problem Statement
You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

## Examples
```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

## Approach
**Key Insight**: Use min-heap to always get the smallest node from k lists.

**Algorithm**:
1. Initialize min-heap with first node of each list
2. Create dummy node
3. While heap not empty:
   - Pop smallest node, add to result
   - If has next, push next to heap
4. Return dummy.next

**Why this works**:
- Heap always gives smallest
- O(n log k) time, n total nodes
- Efficient for merging

## Complexity Analysis
- **Time Complexity**: O(n log k)
- **Space Complexity**: O(k)

## Key Insights
- Priority queue for merging
- Handles empty lists
- Preserves order

## Alternative Approaches
1. **Divide and Conquer**: Pairwise merge
2. **Brute Force**: Collect all, sort

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
Test Case 1: [[1,4,5],[1,3,4],[2,6]] -> [1,1,2,3,4,4,5,6]
Test Case 2: [] -> []
```

## Edge Cases
1. All empty lists
2. One list
3. Lists with one node
4. k=0

## Follow-up Questions
1. What if merge sorted arrays?
2. What if external sort?
3. What if find median?
