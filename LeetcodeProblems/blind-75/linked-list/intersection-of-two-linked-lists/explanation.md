# Intersection of Two Linked Lists - Problem #160

## Problem Statement
Given the heads of two singly linked-lists `headA` and `headB`, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

- intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
- listA - The first linked list.
- listB - The second linked list.
- skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
- skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, `headA` and `headB` to your program. If you correctly return the intersected node, then your solution will be accepted.

## Examples
```
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 (3rd node in A and 4th node in B) point to the same location in memory.
```

## Approach
**Key Insight**: Use two pointers traversing both lists, switching heads when reaching end, they meet at intersection.

**Algorithm**:
1. a = headA, b = headB
2. While a != b:
   a = headB if a null else a.next
   b = headA if b null else b.next
3. Return a (intersection or null)

**Why this works**:
- Both travel lenA + lenB
- Meet at intersection if exists
- O(m + n) time, O(1) space

## Complexity Analysis
- **Time Complexity**: O(m + n)
- **Space Complexity**: O(1)

## Key Insights
- Equalizes path lengths by switching
- Handles no intersection (meet at null)
- No modification to lists

## Alternative Approaches
1. **Hash Set**: Store nodes of one, check other
2. **Length Diff**: Calculate lengths, advance longer

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
Test Case 1: Intersect at 8 as above
Test Case 2: No intersection -> null
```

## Edge Cases
1. No intersection
2. Intersect at head
3. One list empty
4. Both empty

## Follow-up Questions
1. What if cycles?
2. What if multiple intersections?
3. What if find all intersections?
