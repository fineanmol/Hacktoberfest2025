# Remove Nth Node From End of List - Problem #19

## Problem Statement
Given the `head` of a linked list, remove the `n`th node from the end of the list and return its head.

## Examples
```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Input: head = [1], n = 1
Output: []
```

## Approach
**Key Insight**: Use two pointers, fast ahead by n steps, then move together until fast ends, slow at removal point.

**Algorithm**:
1. Dummy node before head
2. Fast moves n+1 steps
3. Move slow and fast until fast null
4. slow.next = slow.next.next
5. Return dummy.next

**Why this works**:
- One pass
- Handles removal of head
- O(n) time

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

## Key Insights
- Dummy for head removal
- Fast ahead by n+1 for one step removal
- Works for n=1 to n=len

## Alternative Approaches
1. **Two Passes**: Find length, then remove
2. **Recursion**: Count from end

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
Test Case 1: [1,2,3,4,5], 2 -> [1,2,3,5]
Test Case 2: [1], 1 -> []
```

## Edge Cases
1. Remove head
2. Remove last
3. Single node
4. n = list length

## Follow-up Questions
1. What if remove all occurrences?
2. What if from sorted list?
3. What if doubly linked?
