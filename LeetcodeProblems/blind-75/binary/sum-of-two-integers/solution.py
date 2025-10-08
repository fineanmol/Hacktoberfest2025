# Sum of Two Integers - LeetCode #371

class Solution:
    def getSum(self, a: int, b: int) -> int:
        # 32-bit mask
        mask = 0xFFFFFFFF
        while b != 0:
            carry = (a & b) << 1
            a = (a ^ b) & mask
            b = carry & mask
        
        # For negative numbers
        return a if a <= 0x7FFFFFFF else ~(a ^ mask)
