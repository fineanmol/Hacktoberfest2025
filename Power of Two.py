class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        while n%2==0:
            n//=2
        if n==1:
            return True
        else:
            return False
