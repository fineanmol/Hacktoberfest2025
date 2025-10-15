"""
LeetCode Problem 440: K-th Smallest in Lexicographical Order
Difficulty: Hard

Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

Example 1:
Input: n = 13, k = 2
Output: 10

Example 2:
Input: n = 1, k = 1
Output: 1

Constraints:
- 1 <= k <= n <= 10^9

Time Complexity: O(log n * log n)
Space Complexity: O(1)
"""

class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        def count_steps(curr: int, n: int) -> int:
            steps = 0
            first = curr
            last = curr
            
            while first <= n:
                steps += min(n + 1, last + 1) - first
                first *= 10
                last = last * 10 + 9
                
            return steps
        
        current = 1
        k -= 1
        
        while k > 0:
            steps = count_steps(current, n)
            
            if steps <= k:
                current += 1
                k -= steps
            else:
                current *= 10
                k -= 1
                
        return current


def test_solution():
    sol = Solution()
    
    test_cases = [
        (13, 2, 10),
        (1, 1, 1),
        (100, 10, 17),
        (10, 3, 2),
    ]
    
    for n, k, expected in test_cases:
        result = sol.findKthNumber(n, k)
        print(f"n={n}, k={k} -> {result} (Expected: {expected}) {'✓' if result == expected else '✗'}")


if __name__ == "__main__":
    test_solution()
