// Palindromic Substrings - LeetCode #647

/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
    let count = 0;
    
    for (let i = 0; i < s.length; i++) {
        // Odd length
        count += expand(s, i, i);
        // Even length
        count += expand(s, i, i + 1);
    }
    
    return count;
};

function expand(s, left, right) {
    let count = 0;
    while (left >= 0 && right < s.length && s[left] === s[right]) {
        count++;
        left--;
        right++;
    }
    return count;
}
