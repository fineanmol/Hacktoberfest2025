# Merge Intervals - Problem #56

## Problem Statement
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

## Examples
```
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

## Approach
1. Sort intervals by start time
2. Iterate and merge if current end >= next start
3. Add merged or new interval to result

## Complexity
- Time: O(n log n) due to sorting
- Space: O(n) for result

... (full explanation)
