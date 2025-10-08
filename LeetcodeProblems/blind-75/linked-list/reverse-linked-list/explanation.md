# Reverse Linked List - Problem #206

## Problem Statement
Given the `head` of a singly linked list, reverse the list, and return the reversed list.

## Examples
```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Input: head = [1,2]
Output: [2,1]
```

## Approach
**Key Insight**: Iterative reversal by changing next pointers.

**Algorithm**:
1. Initialize prev = null, curr = head
2. While curr:
   - Save next = curr.next
   - curr.next = prev
   - prev = curr
   - curr = next
3. Return prev (new head)

**Why this works**:
- O(n) time
- O(1) space
- Reverses pointers in place

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

## Key Insights
- Handle null head
- Works for empty list
- Iterative avoids stack overflow

## Alternative Approaches
1. **Recursive**: Base case null, recurse and reverse
2. **Stack**: Push nodes, pop to new list

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
Test Case 1: [1,2,3,4,5] -> [5,4,3,2,1]
Test Case 2: [1,2] -> [2,1]
Test Case 3: [] -> []
```

## Edge Cases
1. Empty list
2. Single node
3. Two nodes

## Follow-up Questions
1. What if reverse from m to n?
2. What if k groups?
3. What if doubly linked?
