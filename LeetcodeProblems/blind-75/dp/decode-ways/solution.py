# Decode Ways - LeetCode #91

class Solution:
    def numDecodings(self, s: str) -> int:
        if not s:
            return 0
        
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1 if s[0] != '0' else 0
        
        for i in range(2, n + 1):
            one_digit = int(s[i-1:i])
            two_digits = int(s[i-2:i])
            
            if 1 <= one_digit <= 9:
                dp[i] += dp[i-1]
            
            if 10 <= two_digits <= 26:
                dp[i] += dp[i-2]
        
        return dp[n]
