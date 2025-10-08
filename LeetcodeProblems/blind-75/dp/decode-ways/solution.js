// Decode Ways - LeetCode #91

/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
    if (!s || s.length === 0) return 0;
    
    const n = s.length;
    const dp = new Array(n + 1).fill(0);
    dp[0] = 1;
    dp[1] = s[0] === '0' ? 0 : 1;
    
    for (let i = 2; i <= n; i++) {
        const oneDigit = parseInt(s.substring(i-1, i));
        const twoDigits = parseInt(s.substring(i-2, i));
        
        if (oneDigit >= 1 && oneDigit <= 9) {
            dp[i] += dp[i-1];
        }
        
        if (twoDigits >= 10 && twoDigits <= 26) {
            dp[i] += dp[i-2];
        }
    }
    
    return dp[n];
};
