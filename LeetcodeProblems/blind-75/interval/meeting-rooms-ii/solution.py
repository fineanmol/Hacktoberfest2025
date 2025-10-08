# Meeting Rooms II - LeetCode #253

from typing import List
import heapq

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        
        intervals.sort(key=lambda x: x[0])
        
        heap = [intervals[0][1]]
        
        for interval in intervals[1:]:
            if interval[0] >= heap[0]:
                heapq.heappop(heap)
            heapq.heappush(heap, interval[1])
        
        return len(heap)
