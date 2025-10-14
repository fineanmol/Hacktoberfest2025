# Problem: Longest Substring Without Repeating Characters
# Goal: Find the length of the longest substring in a given string without repeating characters.
# Technique: Sliding Window + Hash Map for character index tracking

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        Function to calculate the length of the longest substring without repeating characters.

        Args:
        s (str): Input string.

        Returns:
        int: Length of the longest substring with unique characters.
        """

        # Dictionary to store the last index of each character encountered
        char_index = {}

        # Left pointer of the sliding window
        left = 0

        # Variable to keep track of maximum length of substring found
        max_len = 0

        # Iterate over the string using right pointer
        for right, ch in enumerate(s):
            # If character is already in substring, move the left pointer
            if ch in char_index and char_index[ch] >= left:
                left = char_index[ch] + 1  # Skip past the previous occurrence

            # Update the last seen index of the current character
            char_index[ch] = right

            # Update max_len if current window length is larger
            max_len = max(max_len, right - left + 1)

        return max_len


if __name__ == "__main__":
    solution = Solution()

    # ------------------------
    # Regular Test Cases
    # ------------------------
    test_cases = [
        ("abcabcbb", 3),  # Typical case with repeating characters
        ("bbbbb", 1),     # All characters same
        ("pwwkew", 3),    # Mix of repeats
        ("", 0),          # Empty string
        ("a", 1),         # Single character string
        ("dvdf", 3),      # Repeats separated by other characters
    ]

    # ------------------------
    # Edge Cases
    # ------------------------
    edge_cases = [
        ("123!@#123!@", 6),               # Numbers + symbols with repeats
        ("abcdefghijklmnopqrstuvwxyz", 26),  # All unique characters
        ("aaaaaaaaaaaaaaaaaa", 1),        # All repeating characters
        ("a1b2c3d4e5f6g7h8i9j0", 20),    # Long string with numbers
        ("!@#$%^&*()!@#$%^&*()", 10),     # Symbols repeating
        ("a"*10000, 1),                    # Very long repeating string (stress test)
    ]

    # Combine all tests
    all_tests = test_cases + edge_cases

    # ------------------------
    # Run and print test results
    # ------------------------
    for s, expected in all_tests:
        result = solution.lengthOfLongestSubstring(s)
        # Truncate long inputs for readability
        print(f"Input: {s[:30]}{'...' if len(s) > 30 else ''} | Output: {result} | Expected: {expected} | {'PASS' if result == expected else 'FAIL'}")
