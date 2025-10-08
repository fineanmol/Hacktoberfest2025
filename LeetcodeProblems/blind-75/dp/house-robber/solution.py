# House Robber - LeetCode #198

from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        
        prev = nums[0]
        curr = max(nums[0], nums[1])
        
        for i in range(2, len(nums)):
            temp = max(prev + nums[i], curr)
            prev = curr
            curr = temp
        
        return curr
