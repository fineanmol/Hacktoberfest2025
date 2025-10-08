# Odd Even Linked List - Problem #328

## Problem Statement
Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

## Examples
```
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
```

## Approach
**Key Insight**: Maintain two pointers for odd and even, link them alternately, then connect odd tail to even head.

**Algorithm**:
1. odd = head, even = head.next, evenHead = even
2. While even and even.next:
   odd.next = even.next, odd = odd.next
   even.next = odd.next, even = even.next
3. odd.next = evenHead

**Why this works**:
- O(n) time
- O(1) space
- Preserves relative order

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

## Key Insights
- Indices 1-based (1 odd, 2 even)
- Handles odd/even lengths
- No new nodes created

## Alternative Approaches
1. **Collect odd/even lists separately, then merge**
2. **Recursion** (higher space)

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
Test Case 1: [1,2,3,4,5] -> [1,3,5,2,4]
Test Case 2: [2,1,3,5,6,4,7] -> [2,3,6,7,1,5,4]
```

## Edge Cases
1. Empty list
2. Single node
3. Two nodes
4. All odd/even length

## Follow-up Questions
1. What if group by value parity?
2. What if k groups?
3. What if circular list?
