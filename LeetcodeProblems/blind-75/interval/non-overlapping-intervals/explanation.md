# Non-overlapping Intervals - Problem #435

## Problem Statement
Given an array of intervals `intervals` where `intervals[i] = [starti, endi]`, return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

## Examples
```
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
```

## Approach
1. Sort by end time
2. Iterate, count overlaps (start < previous end)
3. Update end if no overlap

## Complexity
- Time: O(n log n)
- Space: O(1)

... (full explanation)
