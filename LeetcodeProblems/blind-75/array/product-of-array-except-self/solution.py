# Product of Array Except Self - LeetCode #238

from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n
        
        # Left products
        left = 1
        for i in range(n):
            result[i] = left
            left *= nums[i]
        
        # Right products
        right = 1
        for i in range(n-1, -1, -1):
            result[i] *= right
            right *= nums[i]
        
        return result
