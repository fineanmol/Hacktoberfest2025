# Merge Intervals - LeetCode #56

from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        
        intervals.sort(key=lambda x: x[0])
        
        result = [intervals[0]]
        
        for interval in intervals:
            current = result[-1]
            if interval[0] <= current[1]:
                current[1] = max(current[1], interval[1])
            else:
                result.append(interval)
        
        return result
