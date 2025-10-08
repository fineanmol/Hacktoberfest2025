# Merge Two Sorted Lists - Problem #21

## Problem Statement
You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

## Examples
```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []
```

## Approach
**Key Insight**: Use dummy node and iterate, choosing smaller node each time.

**Algorithm**:
1. Create dummy node
2. While both lists non-null:
   - Append smaller node to current
   - Move pointer of chosen list
3. Append remaining list
4. Return dummy.next

**Why this works**:
- O(m + n) time
- O(1) space
- Maintains sorted order

## Complexity Analysis
- **Time Complexity**: O(m + n)
- **Space Complexity**: O(1)

## Key Insights
- Dummy simplifies head handling
- Handles unequal lengths
- Works for empty lists

## Alternative Approaches
1. **Recursive**: Merge recursively
2. **Priority Queue**: For k lists

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
Test Case 1: [1,2,4], [1,3,4] -> [1,1,2,3,4,4]
Test Case 2: [], [] -> []
```

## Edge Cases
1. One empty list
2. Both empty
3. Lists with one node
4. One much longer

## Follow-up Questions
1. What if merge k lists?
2. What if not sorted?
3. What if reverse merge?
