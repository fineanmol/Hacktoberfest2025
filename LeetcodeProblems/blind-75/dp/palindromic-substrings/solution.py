# Palindromic Substrings - LeetCode #647

class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0
        
        for i in range(len(s)):
            # Odd length
            count += self.expand(s, i, i)
            # Even length
            count += self.expand(s, i, i + 1)
        
        return count
    
    def expand(self, s: str, left: int, right: int) -> int:
        local_count = 0
        while left >= 0 and right < len(s) and s[left] == s[right]:
            local_count += 1
            left -= 1
            right += 1
        return local_count
