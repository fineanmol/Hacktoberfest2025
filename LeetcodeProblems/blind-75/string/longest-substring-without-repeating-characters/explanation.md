# Longest Substring Without Repeating Characters

## Problem Statement
Given a string s, find the length of the longest substring without repeating characters.

## Examples

### Example 1:
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

### Example 2:
```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

### Example 3:
```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
```

## Approach

### Method: Sliding Window with Hash Set
**Key Insight**: Use a sliding window approach with a hash set to track unique characters.

**Steps**:
1. Use two pointers (left and right) to maintain a sliding window
2. Use a hash set to track characters in the current window
3. Expand the window by moving the right pointer
4. When a duplicate is found, contract the window by moving the left pointer
5. Keep track of the maximum length seen so far

**Time Complexity**: O(n)
**Space Complexity**: O(min(m, n)) where m is the size of the character set

## Solution Code

### Java
```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxLength = 0;
        int left = 0;
        Set<Character> charSet = new HashSet<>();
        
        for (int right = 0; right < n; right++) {
            char currentChar = s.charAt(right);
            
            while (charSet.contains(currentChar)) {
                charSet.remove(s.charAt(left));
                left++;
            }
            
            charSet.add(currentChar);
            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
}
```

### JavaScript
```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    const n = s.length;
    let maxLength = 0;
    let left = 0;
    const charSet = new Set();
    
    for (let right = 0; right < n; right++) {
        const currentChar = s[right];
        
        while (charSet.has(currentChar)) {
            charSet.delete(s[left]);
            left++;
        }
        
        charSet.add(currentChar);
        maxLength = Math.max(maxLength, right - left + 1);
    }
    
    return maxLength;
};
```

### Python
```python
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
```

## Key Insights

1. **Sliding Window**: Maintain a window of unique characters
2. **Hash Set**: Efficiently track characters in the current window
3. **Two Pointers**: Use left and right pointers to expand and contract the window
4. **Character Removal**: Remove characters from the set when contracting the window

## Test Cases

### Test Case 1: Normal case
```
Input: "abcabcbb"
Output: 3
```

### Test Case 2: All same characters
```
Input: "bbbbb"
Output: 1
```

### Test Case 3: Mixed case
```
Input: "pwwkew"
Output: 3
```

### Test Case 4: Empty string
```
Input: ""
Output: 0
```

### Test Case 5: Single character
```
Input: "a"
Output: 1
```

## Follow-up Questions

1. What if we need to return the actual substring instead of just the length?
2. What if the string contains Unicode characters?
3. What if we need to find all substrings with maximum length?
4. What if we need to handle case-insensitive comparison?
