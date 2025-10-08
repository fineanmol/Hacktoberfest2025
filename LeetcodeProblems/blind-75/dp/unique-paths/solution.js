// Unique Paths - LeetCode #62

/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    const dp = Array.from({length: m}, () => Array(n).fill(0));
    
    // First row
    for (let j = 0; j < n; j++) {
        dp[0][j] = 1;
    }
    
    // First column
    for (let i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    
    return dp[m - 1][n - 1];
};
