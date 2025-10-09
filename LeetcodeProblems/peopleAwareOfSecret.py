class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        MOD = 10**9 + 7
        if n == 1:
            return 1
        dp = [0] * (n + 1)
        dp[1] = 1
        window = 0
        for i in range(2, n + 1):
            enter = i - delay
            exit_ = i - forget
            if enter >= 1:
                window = (window + dp[enter]) % MOD
            if exit_ >= 1:
                window = (window - dp[exit_] + MOD) % MOD
            dp[i] = window
        start = max(1, n - forget + 1)
        ans = sum(dp[start: n+1]) % MOD
        return ans
