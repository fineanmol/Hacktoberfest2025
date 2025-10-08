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