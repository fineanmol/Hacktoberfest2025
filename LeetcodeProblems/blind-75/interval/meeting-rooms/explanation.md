# Meeting Rooms - Problem #252 (LeetCode Premium)

## Problem Statement
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

## Examples
```
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

Input: intervals = [[7,10],[2,4]]
Output: true
```

## Approach
1. Sort by start time
2. Check if any start < previous end

## Complexity
- Time: O(n log n)
- Space: O(1)

... (full explanation)
