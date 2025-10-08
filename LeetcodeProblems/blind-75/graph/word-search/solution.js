// Word Search - LeetCode #79

/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    const m = board.length;
    const n = board[0].length;
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (dfs(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    
    return false;
};

function dfs(board, word, i, j, index) {
    if (index === word.length) return true;
    
    const m = board.length;
    const n = board[0].length;
    
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] !== word[index]) return false;
    
    const temp = board[i][j];
    board[i][j] = '#'; // Visited
    
    const found = dfs(board, word, i - 1, j, index + 1) ||
                  dfs(board, word, i + 1, j, index + 1) ||
                  dfs(board, word, i, j - 1, index + 1) ||
                  dfs(board, word, i, j + 1, index + 1);
    
    board[i][j] = temp; // Backtrack
    
    return found;
}
