/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    const m = board.length;
    const n = board[0].length;
    const visited = Array(m).fill().map(() => Array(n).fill(false));
    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    
    function dfs(i, j, index) {
        if (index === word.length) {
            return true;
        }
        
        if (i < 0 || i >= m || j < 0 || j >= n || 
            visited[i][j] || board[i][j] !== word[index]) {
            return false;
        }
        
        visited[i][j] = true;
        
        for (const [di, dj] of directions) {
            if (dfs(i + di, j + dj, index + 1)) {
                return true;
            }
        }
        
        visited[i][j] = false;
        return false;
    }
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (dfs(i, j, 0)) {
                return true;
            }
        }
    }
    
    return false;
};
