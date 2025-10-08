// Number of Islands - LeetCode #200

/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    if (!grid || grid.length === 0) return 0;
    
    const m = grid.length;
    const n = grid[0].length;
    let count = 0;
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === '1') {
                dfs(grid, i, j);
                count++;
            }
        }
    }
    
    return count;
};

function dfs(grid, i, j) {
    const m = grid.length;
    const n = grid[0].length;
    
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] !== '1') return;
    
    grid[i][j] = '0'; // Visited
    
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
}
