# Meeting Rooms II - Problem #253 (LeetCode Premium)

## Problem Statement
Given an array of meeting time intervals `intervals` where `intervals[i] = [starti, endi]`, return the minimum number of conference rooms required.

## Examples
```
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

Input: intervals = [[7,10],[2,4]]
Output: 1
```

## Approach
1. Sort by start time
2. Use min-heap for end times
3. If new start >= earliest end, reuse room (pop and push)
4. Else, add new room (push)
5. Heap size = rooms needed

## Complexity
- Time: O(n log n)
- Space: O(n)

... (full explanation)
