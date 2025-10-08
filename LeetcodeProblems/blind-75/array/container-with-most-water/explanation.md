# Container With Most Water - Problem #11

## Problem Statement
You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `i`th line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

## Examples
```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Input: height = [1,1]
Output: 1
```

## Approach
**Key Insight**: Use two pointers starting from both ends, moving the smaller height pointer inward.

**Algorithm**:
1. Initialize left=0, right=n-1, maxArea=0
2. While left < right:
   - Calculate area = min(height[left], height[right]) * (right - left)
   - Update maxArea
   - Move the pointer with smaller height
3. Return maxArea

**Why this works**:
- O(n) time - Single pass with two pointers
- Always considers the widest possible container first
- Moving smaller pointer can potentially increase area

## Complexity Analysis
- **Time Complexity**: O(n) - Linear time
- **Space Complexity**: O(1) - Constant space

## Key Insights
- Greedy choice: Always move the limiting (smaller) height
- Proof: Moving taller doesn't decrease width without potential gain
- Handles varying heights efficiently

## Alternative Approaches
1. **Brute Force**: Check all pairs (O(n²) time)
2. **Stack-based**: For more complex variations

## Solutions in Different Languages

### Java
```java
// ... code here ...
```

### JavaScript
```javascript
// ... code here ...
```

### Python
```python
# ... code here ...
```

## Test Cases
```
Test Case 1:
Input: [1,8,6,2,5,4,8,3,7]
Expected: 49

Test Case 2:
Input: [1,1]
Expected: 1
```

## Edge Cases
1. Two bars
2. All bars same height
3. Increasing heights
4. Decreasing heights
5. Minimum n=2

## Follow-up Questions
1. What if bars can be slanted?
2. What if find minimum area?
3. What if 3D container?
