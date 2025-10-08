# Reorder List - Problem #143

## Problem Statement
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

## Examples
```
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
```

## Approach
**Key Insight**: Find middle, reverse second half, then merge alternately.

**Algorithm**:
1. Find middle with slow/fast pointers
2. Reverse the second half
3. Merge first and reversed second alternately

**Why this works**:
- O(n) time
- O(1) space
- Modifies pointers in place

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

## Key Insights
- Slow/fast for middle
- Standard reverse list
- Careful merge to avoid cycles

## Alternative Approaches
1. **Use Stack**: Push second half, pop and insert
2. **Recursion**: But higher space

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
Test Case 1: [1,2,3,4] -> [1,4,2,3]
Test Case 2: [1,2,3,4,5] -> [1,5,2,4,3]
```

## Edge Cases
1. Empty list
2. Single node
3. Two nodes
4. Odd/even length

## Follow-up Questions
1. What if reorder in different pattern?
2. What if k-way reorder?
3. What if circular list?
