# Combination Sum - LeetCode #39

from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        
        def backtrack(temp: List[int], remain: int, start: int):
            if remain < 0:
                return
            if remain == 0:
                result.append(temp[:])
                return
            
            for i in range(start, len(candidates)):
                temp.append(candidates[i])
                backtrack(temp, remain - candidates[i], i)
                temp.pop()
        
        backtrack([], target, 0)
        return result
