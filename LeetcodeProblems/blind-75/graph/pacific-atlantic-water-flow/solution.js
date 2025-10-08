// Pacific Atlantic Water Flow - LeetCode #417

/**
 * @param {number[][]} heights
 * @return {number[][]}
 */
var pacificAtlantic = function(heights) {
    const result = [];
    if (!heights || heights.length === 0 || heights[0].length === 0) return result;
    
    const m = heights.length;
    const n = heights[0].length;
    
    const pacific = Array.from({length: m}, () => Array(n).fill(false));
    const atlantic = Array.from({length: m}, () => Array(n).fill(false));
    
    // DFS from borders
    for (let i = 0; i < m; i++) {
        dfs(heights, pacific, Number.MIN_SAFE_INTEGER, i, 0);
        dfs(heights, atlantic, Number.MIN_SAFE_INTEGER, i, n - 1);
    }
    
    for (let j = 0; j < n; j++) {
        dfs(heights, pacific, Number.MIN_SAFE_INTEGER, 0, j);
        dfs(heights, atlantic, Number.MIN_SAFE_INTEGER, m - 1, j);
    }
    
    // Find intersection
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                result.push([i, j]);
            }
        }
    }
    
    return result;
};

function dfs(heights, visited, height, x, y) {
    const m = heights.length;
    const n = heights[0].length;
    
    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || heights[x][y] < height) return;
    
    visited[x][y] = true;
    
    dfs(heights, visited, heights[x][y], x - 1, y);
    dfs(heights, visited, heights[x][y], x + 1, y);
    dfs(heights, visited, heights[x][y], x, y - 1);
    dfs(heights, visited, heights[x][y], x, y + 1);
}
