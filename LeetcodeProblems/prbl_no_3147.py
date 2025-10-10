#3147. Taking Maximum Energy From the Mystic Dungeon
class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        n = len(energy)
        dp = [0] * n
        result = float('-inf')
        for i in range(n - 1, -1, -1):
            dp[i] = energy[i] + (dp[i + k] if i + k < n else 0)
            result = max(result, dp[i])
        return result