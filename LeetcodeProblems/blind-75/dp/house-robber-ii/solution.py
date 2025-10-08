# House Robber II - LeetCode #213

from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        
        # Rob without first
        max1 = self.rob_linear(nums, 1, len(nums) - 1)
        # Rob without last
        max2 = self.rob_linear(nums, 0, len(nums) - 2)
        
        return max(max1, max2)
    
    def rob_linear(self, nums: List[int], start: int, end: int) -> int:
        if start > end:
            return 0
        
        prev = 0
        curr = 0
        
        for i in range(start, end + 1):
            temp = max(prev + nums[i], curr)
            prev = curr
            curr = temp
        
        return curr
