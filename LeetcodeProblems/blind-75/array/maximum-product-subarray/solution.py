# Maximum Product Subarray - LeetCode #152

from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        max_prod = nums[0]
        min_prod = nums[0]
        result = nums[0]
        
        for i in range(1, len(nums)):
            temp_max = max(nums[i], max_prod * nums[i], min_prod * nums[i])
            min_prod = min(nums[i], max_prod * nums[i], min_prod * nums[i])
            max_prod = temp_max
            
            result = max(result, max_prod)
        
        return result
