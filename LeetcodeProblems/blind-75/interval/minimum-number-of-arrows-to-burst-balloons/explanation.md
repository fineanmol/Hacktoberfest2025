# Minimum Number of Arrows to Burst Balloons - Problem #452

## Problem Statement
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array `points` where `points[i] = [xstart, xend]` denotes a balloon whose horizontal diameter stretches between `xstart` and `xend`. Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis.

A balloon with `xstart` and `xend` is burst by an arrow shot at `x` if `xstart <= x <= xend`. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array `points`, return the minimum number of arrows that must be shot to burst all balloons.

## Examples
```
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [1,6] and [2,8].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
```

## Approach
1. Sort balloons by end point
2. Shoot at end of first, count=1
3. For each, if start > previous shoot, shoot new at its end, count++

## Complexity
- Time: O(n log n)
- Space: O(1)

Greedy: Shoot as late as possible to cover more.

... (full explanation)
