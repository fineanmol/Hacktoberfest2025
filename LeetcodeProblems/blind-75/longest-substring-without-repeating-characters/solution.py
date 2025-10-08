class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        max_length = 0
        left = 0
        char_set = set()
        
        for right in range(n):
            current_char = s[right]
            
            while current_char in char_set:
                char_set.remove(s[left])
                left += 1
            
            char_set.add(current_char)
            max_length = max(max_length, right - left + 1)
        
        return max_length